#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define INF 1e18

struct edge {
    int u, v, w;
    edge(int u, int v, int w): u(u), v(v), w(w) {}
};

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<edge> edges;
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, type;
        cin >> u >> v >> type;
        if (type == 0) {
            edges.eb(u, v, 1);
            edges.eb(v, u, 1);
            adj[u].eb(v, 1);
            adj[v].eb(u, 1);
        } else {
            edges.eb(u, v, 1);
            edges.eb(v, u, -1);
            adj[u].eb(v, 1);
            adj[v].eb(u, -1);
        }
    }

    vector<int> dist(n + 1);
    fill(dist.begin(), dist.end(), INF);
    dist[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (auto &[u, v, w]: edges) {
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    bool neg_cycle = false;
    for (auto &[u, v, w]: edges) {
        if (dist[v] > dist[u] + w) {
            neg_cycle = true;
        }
    }

    if (neg_cycle) {
        cout << "NO\n";
        return 0;
    }

    vector<int> color(n + 1);

    bool bipartite = true;

    function<void(int, int, int)> dfs = [&](int u, int p, int col) {
        color[u] = col;
        for (pi pr: adj[u]) {
            int v = pr.f;
            if (v != p) {
                if (color[v] == color[u]) {
                    bipartite = false;
                }
                if (!color[v]) {
                    dfs(v, u, 3 - col);
                }
            }
        }
    };

    dfs(1, 1, 1);

    if (!bipartite) {
        cout << "NO\n";
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) dp[i][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (auto &[v, w]: adj[i]) {
            dp[i][v] = w;
        }
    }

    pi best_uv = {0, 0};
    int max_dist = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] > max_dist) {
                best_uv = {i, j};
                max_dist = dp[i][j];
            }
        }
    }

    int u = best_uv.f;
    int v = best_uv.s;
    // cout << "u: " << u << "\n";
    // cout << "v: " << v << "\n";
    cout << "YES\n";
    cout << dp[u][v] << "\n";
    for (int i = 1; i <= n; i++) {
        cout << dp[u][i] << " ";
    }
    cout << "\n";






}