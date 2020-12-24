//1280 D

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
const int inf = 1e18;

int t;
const int maxn = 3005;

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        vector<vector<int>> adj(n + 1);

        for (int i = 1; i <= n; i++) {
            int b; cin >> b;
            a[i] -= b;
        }
        for (int i = 1; i <= n; i++) {
            int w; cin >> w;
            a[i] += w;
        }

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v), adj[v].pb(u);
        }

        function<vector<pi>(int, int)> dfs = [&](int u, int p) {
            vector<pi> cur_dp = {mp(0, a[u])};
            for (int v: adj[u]) {
                if (v != p) {
                    vector<pi> dp_v = dfs(v, u);
                    vector<pi> next_dp((int)cur_dp.size() + (int)dp_v.size(), mp(-1, -1));
                    for (int i = 0; i < (int)cur_dp.size(); i++) {
                        for (int j = 0; j < (int)dp_v.size(); j++) {
                            pi d1 = cur_dp[i];
                            pi d2 = dp_v[j];
                            // split //1 + 1 = 2 => (0, 0) -> 1
                            next_dp[i + j + 1] = max(next_dp[i + j + 1], mp(d1.f + d2.f + (d2.s > 0), d1.s));
                            // don't split // 1 + (1 - 0) = 1 => (0, 0) -> 0
                            next_dp[i + j] = max(next_dp[i + j], mp(d1.f + d2.f, d1.s + d2.s));
                        }
                    }

                    cur_dp = next_dp;
                }
            }
            return cur_dp;
        };

        vector<pi> res = dfs(1, 1);
        int ans = res[m - 1].f + (res[m - 1].s > 0);
        cout << ans << "\n";
    }
} 