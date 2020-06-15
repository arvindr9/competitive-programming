void bfs(int u, vector<int> & dist) {
    vector<int> visited(n + 1);
    dist[u] = 0;
    visited[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int uu = q.front(); q.pop();
        for (int v: adj[uu]) {
            if (!visited[v]) {
                visited[v] = 1;
                dist[v] = dist[uu] + 1;
                q.push(v);
            }
        }
    }
}
