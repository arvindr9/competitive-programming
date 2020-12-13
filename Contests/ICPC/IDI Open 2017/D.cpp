// IDI Open 2017 D

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int maxn = 21;

int n, m;
// m words

vector<string> words(maxn);
vector<string> cubes(maxn);

typedef long long LL;

struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  
  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(u, v, cap);
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(v, u, 0);
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};


int solve(int mask) {
    int sz = 2;
    vector<char> nodes;
    int n2 = 0;
    vector<string> ss;

    // m words
    for (int i = 0; i < m; i++) {
        if (mask & (1 << i)) {
            ss.pb(words[i + 1]);
        }
    }
    for (string st: ss) {
        int sz = st.size();
        for (int i = 0; i < sz; i++) {
            nodes.pb(st[i]);
            n2++;
        }
    }
    int src = 0;
    int sink = n + n2 + 1;
    // 1 -> n are the cubes
    // n + 1 -> n + n2 are the chars
    Dinic dinic(n + n2 + 2);
    for (int i = 1; i <= n; i++) {
        dinic.AddEdge(src, i, 1);
    }
    for (int i = n + 1; i <= n + n2; i++) {
        dinic.AddEdge(i, sink, 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= n + n2; j++) {
            for (int k = 0; k < 6; k++) {
                if (cubes[i][k] == nodes[j - n - 1] or cubes[i][k] == '*') {
                    dinic.AddEdge(i, j, 1);
                    break;
                }
            }
        }
    }
    int max_matching = dinic.MaxFlow(src, sink);
    int numr = ss.size();
    if (max_matching == n2) {
        int ans = 1;
        for (int i = 2; i <= numr; i++) ans *= i;
        return ans;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> words[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> cubes[i];
    }
    int pwr = 1 << m;
    int ans = 0;
    for (int mask = 1; mask < pwr; mask++) {
        ans += solve(mask);
    }
    cout << ans << "\n";
}