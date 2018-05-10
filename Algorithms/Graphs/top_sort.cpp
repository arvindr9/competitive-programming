#include <bits/stdc++.h>

using namespace std;

stack<int> s;
const int maxn = 50000;
vector<int> adj[maxn];
int visited[maxn];

int N, m;

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = true;
    for (int v: adj[u]) {
        dfs(v);
    }
    s.push(u);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= N; i++) {
        dfs(i);
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}