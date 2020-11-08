// BFS (CP handbook)
queue<int> q;
dist[1] = 0;
visited[1] = true;
q.push(1);
while (!q.empty()) {
    int u = q.front();
    q.pop();
    // process u
    for (int v: adj[u]) {
        if (!visited[v]) {
            dist[v] = dist[u] + 1;
            visited[v] = true;
            q.push(v);
        }
    }
}

// Dijkstra (CP handbook)
typedef pair<int, int> pi;
#define mp make_pair
#define s second
#define f first

for (int i = 1; i <= n; i++) {
    dist[i] = INF;
}
priority_queue<pi, vector<pi>, greater<pi> > q;
dist[1] = 0;
q.push(mp(0, 1));
while (!q.empty()) {
    pi p = q.top();
    q.pop();
    int u = p.s;
    if (dist[u] != INF) continue;
    dist[u] = w;
    for (pi p: adj[u]) {
        int v = adj[u].f;
        int w = adj[u].s;
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            q.push(mp(dist[w], w));
        }
    }
}

//0-1 BFS (cp-algorithms)

for (int i = 1; i <= n; i++) {
    dist[i] = INF;
}
deque<int> q;
dist[1] = 0;
q.push_front(1);
while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    for (pi p: adj[u]) {
        int v = p.f;
        int w = p.s;
        if (d[u] + w < d[v]) {
            d[u] = d[v] + 1;
            if (w == 1) {
                q.push_back(v);
            } else {
                q.pop_front(v);
            }
        }
    } 
}

