// 2018 ICPC SER -- Abstract Art
// submit here: https://icpcgate.org/contest/problems.php?cid=114
// based on the official solution from http://serjudging.vanb.org/
// the below finds all possible vertices that can be in an independent set

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

struct Edge {
    int v;
    bool match;
    Edge(int _v, bool _match): v(_v), match(_match) {}
};

const int mx = 1e2 + 5;
const int maxn = 1e4 + 5;
vector<Edge> adj[maxn];
bool matched[maxn], Z[maxn];
char grid[maxn][maxn];
int n, k;

int r, c;

int get_vertex(int i, int j) {
    return c * i + j;
}

pi get_coords(int val) {
    return {val / c, val % c};
}

vector<int> get_independent_set(bool flip) {
    // gets the ind set from one side of the bipartite graph
    queue<int> q;
    for (int u = 0; u < n; u++) {
        auto [i, j] = get_coords(u);
        if ((i + j) % 2 == flip) {
            if (!matched[u]) {
                q.push(u);
                Z[u] = 1;
            }
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        auto [i, j] = get_coords(u);
        for (Edge e: adj[u]) {
            int v = e.v;
            if ((i + j) % 2 == flip) {
                // look for edges that are not matched
                if (!e.match and !Z[v]) {
                    q.push(v);
                    Z[v] = 1;
                }
            } else {
                // look for edges that are matched
                if (e.match and !Z[v]) {
                    q.push(v);
                    Z[v] = 1;
                }
            }
        }
    }
    vector<int> res;
    for (int u = 0; u < n; u++) {
        auto [i, j] = get_coords(u);
        if (grid[i][j] == '#') continue;
        if ((i + j) % 2 == flip) {
            if (Z[u]) {
                res.pb(u);
            }
        } else {
            if (!Z[u]) {
                res.pb(u);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        Z[i] = 0;
    }
    return res;
}

bool valid(int i, int j) {
    return i >= 0 and i < r and j >= 0 and j < c;
}

vector<pi> getValids(int i, int j) {
    vector<pi> res;
    for (auto [dx, dy]: {mp(-1, 0), mp(1, 0), mp(0, 1), mp(0, -1)}) {
        int i2 = i + dx;
        int j2 = j + dy;
        if (valid(i2, j2)) {
            if (grid[i2][j2] != grid[i][j] and grid[i2][j2] != '#') res.emplace_back(i2, j2);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    n = r * c;
    for (int i = 0; i < r; i++) {
        string st;
        cin >> st;
        for (int j = 0; j < c; j++) {
            grid[i][j] = st[j]; 
        }
    }
    // run Kuhn to get matching
    Kuhn kuhn(n);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int u = get_vertex(i, j);
            if ((i + j) % 2 == 0) {
                if (grid[i][j] == '#') continue;
                for(auto [i2, j2]: getValids(i, j)) {
                    int v = get_vertex(i2, j2);
                    kuhn.addEdge(u, v); // add edge for kuhn
                }
            }
        }
    }
    kuhn.match();
    vector<pi> matching = kuhn.get_matching();
    for (auto [u, v]: matching) {
        matched[u] = matched[v] = 1;
    }

    // get independent sets
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int u = get_vertex(i, j);
            if ((i + j) % 2 == 0) {
                if (grid[i][j] == '#') continue;
                for(auto [i2, j2]: getValids(i, j)) {
                    int v = get_vertex(i2, j2);
                    bool match = kuhn.mt[v] == u;
                    adj[u].emplace_back(v, match);
                    adj[v].emplace_back(u, match);
                }
            }
        }
    }
    vector<int> i1 = get_independent_set(0);
    vector<int> i2 = get_independent_set(1);
    vector<char> ans;
    for (int u: i1) {
        auto [i, j] = get_coords(u);
        ans.pb(grid[i][j]);
    }
    for (int u: i2) {
        auto [i, j] = get_coords(u);
        ans.pb(grid[i][j]);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << matching.size() << "\n";
    for (char elt: ans) {
        cout << elt;
    }
    cout << "\n";
}