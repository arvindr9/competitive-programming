// 1463 E

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

const int maxn = 3e5 + 5;
vector<int> adj1[maxn], adj2[maxn];
vector<int> ans;
int n, k;
int visited1[maxn], visited2[maxn], visited3[maxn];
int deg[maxn];
int comp[maxn], head[maxn];
int prv[maxn], nxt[maxn];
vector<int> comp_reps[maxn];
int numc = 0;
bool possible = true;

void dfs1(int u) {
    visited1[u] = 1;
    for (int v: adj1[u]) {
        if (visited1[v] == 1) {
            possible = false;
            return;
        }
        if (!visited1[v]) dfs1(v);
    }
    visited1[u] = 2;
}

void dfs2(int u) {
    comp[u] = numc;
    comp_reps[numc].pb(u);
    if (nxt[u]) dfs2(nxt[u]);
}

void dfs3(int u) {
    visited3[u] = 1;
    for (int v: adj2[u]) {
        if (!visited3[v]) {
            dfs3(v);
        }
    }
    ans.pb(u);
}


int2 main() {
    cin >> n >> k;
    vector<pi> edges1;
    vector<int> prereqs(n + 1);
    int rt = -1;
    for (int i = 1; i <= n; i++) {
        cin >> prereqs[i];
        int p = prereqs[i];
        if (p == 0) rt = i;
        if (p) adj1[p].pb(i), edges1.eb(p, i);
    }

    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        adj1[x].pb(y);
        prv[y] = x, nxt[x] = y;
    }

    for (int i = 1; i <= n; i++) if (!visited1[i]) dfs1(i);

    if (!possible) {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) if (!prv[i] and !visited2[i]) numc++, head[numc] = i, dfs2(i);

    for (auto &[u, v]: edges1) {
        if (comp[u] != comp[v]) adj2[comp[u]].pb(comp[v]);
    }

    for (int i = 1; i <= numc; i++) {
        vector<int> &edges = adj2[i];
        sort(edges.begin(), edges.end());
        edges.erase(unique(edges.begin(), edges.end()), edges.end());
    }

    vector<pi> edges2;
    for (int i = 1; i <= numc; i++) {
        for (int j: adj2[i]) {
            edges2.eb(i, j);
        }
    }

    for (int i = 1; i <= numc; i++) {
        if (!visited3[i]) dfs3(i);
    }

    // cout << "numc: " << numc << ", ans size: " << ans.size() << "\n";

    if ((int)ans.size() < numc) {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> rank(numc + 1);
    for (int i = 1; i <= numc; i++) {
        rank[ans[numc - i]] = i;
    }

    for (auto &[u, v]: edges2) {
        if (rank[u] > rank[v]) {
            cout << 0 << "\n";
            return 0;
        }
    }

    while (!ans.empty()) {
        int u = ans.back(); ans.pop_back();
        for (int elt: comp_reps[u]) {
            cout << elt << " ";
        }
    }
    cout << "\n";



}