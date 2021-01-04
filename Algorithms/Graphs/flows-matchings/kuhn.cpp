// kuhn bipartite matching. Based on https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html
// Tested here: https://codeforces.com/gym/102423/submission/103312093

#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define pb push_back
#define mp make_pair

struct Kuhn {
    int n;
    vector<vector<int>> adj;
    vector<int> mt;
    vector<int> used;
    Kuhn(int _n): adj(_n), mt(_n, -1), n(_n) {}
    void addEdge(int u, int v) {
        adj[u].pb(v);
    }

    bool try_kuhn(int u) {
        if (used[u]) return false;
        used[u] = true;
        for (int v: adj[u]) {
            if (mt[v] == -1 or try_kuhn(mt[v])) {
                mt[v] = u;
                return true;
            }
        }
        return false;
    }

    void match() {
        for (int i = 0; i < n; i++) {
            if (!adj[i].empty()) { // check if it's in the left side
                used.assign(n, 0);
                try_kuhn(i);
            }
        }
    }

    vector<pi> get_matching() {
        vector<pi> matching;
        for (int i = 0; i < n; i++) {
            if (~mt[i]) {
                matching.emplace_back(mt[i], i);
            }
        }
        return matching;
    }
};


int main() {
    int n, k, m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
    }
    mt.assign(k, -1);
    for (int i = 0; i < n; i++) {
        used.assign(n, -1);
        try_kuhn(i);
    }
    for (int i = 0; i < k; i++) {
        if (mt[i] != -1) {
            cout << mt[i] + 1 << " " << i + 1 << "\n";
        }
    }
}