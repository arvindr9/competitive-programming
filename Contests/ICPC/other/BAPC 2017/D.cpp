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
#define inf 1e18

const int maxn = 1e5 + 5;
int n, m;
vector<pi> adj[maxn];

vector<int> dists(int s) {
    vector<int> res(n);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    fill(res.begin(), res.end(), inf);
    vector<int> visited(n);
    res[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        int u = pq.top().s; pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (auto &[v, w]: adj[u]) {
            if (res[u] + w < res[v]) {
                res[v] = res[u] + w;
                pq.emplace(res[v], v);
            }
        }
    }
    return res;
}
int visited[maxn], prv[maxn];

void dfs(int u) {
    for (auto &[v, w]: adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            prv[v] = u;
            dfs(v);
        }
    }
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].eb(v, d);
        adj[v].eb(u, d);
    }
    vector<int> dist = dists(1);
    vector<int> bad(n);
    for (int i = 0; i < n; i++) {
        if (i == 1) continue;
        int opt = -1;
        int mindist = inf;
        for (auto &[v, w]: adj[i]) {
            if (w + dist[v] < mindist) {
                opt = v;
                mindist = w + dist[v];
            }
        }
        vector<pi> &edges = adj[i];
        edges.erase(remove_if(edges.begin(), edges.end(), [&](auto p){return p.f == opt;}));
        // cout << "i: " << i << ", opt: " << opt << ", mindist: " << mindist << "\n";
    }
    for (int i = 0; i < n; i++) prv[i] = -1;
    prv[0] = 0;
    visited[0] = true;
    dfs(0);
    if (!visited[1]) {
        cout << "impossible\n";
    } else {
        int cur = 1;
        vector<int> ans = {cur};
        while (prv[cur] != cur) {
            cur = prv[cur];
            ans.pb(cur);
        }
        reverse(ans.begin(), ans.end());
        int l = ans.size();
        cout << l << " ";
        for (int elt: ans) {
            cout << elt << " ";
        }
        cout << "\n";
    }
} 