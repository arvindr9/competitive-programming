#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5 + 5;

int visited[maxn];
vector<int> adj[maxn];

int dfs(int u) {
    visited[u] = true;
    for (int v: adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int num_components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            num_components++;
        }
    }
    cout << num_components << "\n";

}