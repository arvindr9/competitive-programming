#include <bits/stdc++.h>
using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define f first
#define s second


int t;

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int num_cycles = 0;
        vector<vector<int>> adj(n + 1);
        vector<int> indeg(n + 1);
        int m2 = m;
        vector<int> to_search;
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            if (u == v) {m2--; continue;}
            adj[u].pb(v), to_search.pb(u), indeg[v]++;
        }
        vector<int> visited(n + 1);

        function<void(int)> dfs = [&](int u) {
            visited[u] = 1;
            for (int v: adj[u]) {
                if (visited[v] == 1) {
                    num_cycles++;
                    return;
                }
                if (!visited[v]) dfs(v);
            }
            visited[u] = 2;
        };

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs(i);
        }
        // for (int elt: to_search) if (indeg[elt] != 0 and !visited[elt]) dfs(elt);
        // cout << "num cycles: " << num_cycles << "\n";
        // cout << "m2:"
        int ans = m2 + num_cycles;
        cout << ans << "\n";
    }
}