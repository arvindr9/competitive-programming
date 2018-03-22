//Fails on test case 4 :(
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1050;
vector<tuple<int, ll, ll>> adj[maxn];
bool visited[maxn];
set<ll> nums;
set<ll> processed;
int n, m;
ll k;
int s, d;

inline void clr() {
    for(int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

void dfs(int a, ll id) {
    if(visited[d] || visited[a]) return;
    visited[a] = true;
    for(auto i: adj[a]) {
        int b = get<0>(i);
        ll mn = get<1>(i);
        ll mx = get<2>(i);
        if(id >= mn && id <= mx) {
            dfs(b, id);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k >> s >> d;
    for(int i = 1; i <= m; i++) {
        int a, b;
        ll mn, mx;
        cin >> a >> b >> mn >> mx;
        adj[a].push_back(make_tuple(b, mn, mx));
        adj[b].push_back(make_tuple(a, mn, mx));
        nums.insert(mn);
        nums.insert(mx);
    }
    long long ans = 0;
    set<ll>::iterator it = nums.begin();
    dfs(s, *it);
    if(visited[d]) ans += 1;
    clr();
    ll prevNum = *it;
    processed.insert(prevNum);
    ll currNum;
    if(prevNum > k) {
        cout << 0 << "\n";
        return 0;
    }
    it++;
    while(it != nums.end() && *it <= k) {
        currNum = *it;
        if(!processed.count(currNum - 1)) {
            dfs(s, currNum - 1);
            if(visited[d]) ans += currNum - prevNum - 1;
            processed.insert(currNum - 1);
            clr();
        }
        dfs(s, currNum);
        processed.insert(currNum);
        if(visited[d]) ans += 1;
        clr();
        it++;
        prevNum = currNum;
    }
    if(k > prevNum) {
        dfs(s, k);
        if(visited[d]) {
            ans += k - prevNum;
        }
    }
    cout << ans << "\n";
}
