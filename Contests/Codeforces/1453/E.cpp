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

int t;

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> sz(n);
        vector<vector<int>> adj(n + 1);

        int ans = 0;

        auto dfs = [&](int u, int p, auto f) { // cost to explore u's subtree from p
            if ((int)adj[u].size() == 1 and u != 1) {
                return 1LL;
            }
            vector<int> costs;
            for (int v: adj[u]) {
                if (v != p) {
                    int res = f(v, u, f);
                    costs.pb(res);
                }
            }
            sort(costs.begin(), costs.end());
            int numc = costs.size();
            if (numc > 1) {
                if (u == 1) {
                    ans = max({ans, costs[numc - 2] + 1, costs.back()}); // child-to-child, going back
                } else {
                    ans = max({ans, costs.back() + 1}); // child-to-child cost
                }
            }
            // cout << "costs[0]: " << costs[0] << "\n";
            ans = max(ans, costs[0]); // if numc == 1?
            return costs[0] + 1LL;
        };

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(1, 1, dfs);
        cout << ans << "\n";



    }
} 