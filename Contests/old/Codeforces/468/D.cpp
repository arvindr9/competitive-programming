#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll maxn = 100050;
vector<ll> adj[maxn];
vector<ll> adj2[maxn];
ll depth[maxn];
ll numd[maxn];
ll maxd;
ll n;
ll ans;

void dfs2(ll u, ll p = 1) {
    depth[u] = depth[p] + 1;
    numd[depth[u]] += 1;
    maxd = max(maxd, depth[u]);
    for(ll v: adj2[u]) {
        if(v != p) {
            dfs2(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 2; i <= n; i++) {
        ll v; cin >> v;
        adj[i].push_back(v);
        adj2[v].push_back(i);
    }
    dfs2(1);
    for(ll i: numd) {
        ans += i % 2;
    }
    cout << ans << "\n";

}
