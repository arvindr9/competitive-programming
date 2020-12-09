#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second

int n;

int dfs(int bit, vector<int> &elts) {
    vector<int> elts0;
    vector<int> elts1;
    for (int elt: elts) {
        if (elt & (1 << bit)) {
            elts0.pb(elt);
        } else {
            elts1.pb(elt);
        }
    }
    int s0 = elts0.size();
    int s1 = elts1.size();
    if (max(s0, s1) < 2) {
        // can keep everything
        return 0;
    }
    if (min(s0, s1) < 2) {
        if (s0 <= 1) {
            return dfs(bit - 1, elts1);
        } else  { //s1 <= 1
            return dfs(bit - 1, elts0);
        }
    }
    int ans1 = (s0 - 1) + dfs(bit - 1, elts1);
    int ans2 = (s1 - 1) + dfs(bit - 1, elts0);
    return min(ans1, ans2);

}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = dfs(29, a);
    cout << ans << "\n";
}