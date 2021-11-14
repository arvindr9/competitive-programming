// SCCs are returned in reverse topological order

#include <bits/stdc++.h>
using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second;
#define inf 1e18

const int maxn = 2e5 + 5;

vector<int> adj[maxn], compadj[maxn];
int low[maxn], pre[maxn], comp[maxn];
int timer = 0;
int comptimer = 0;
vector<int> stk;

int n, m;

void dfs(int u, int p) {
    pre[u] = low[u] = ++timer;
    stk.pb(u);
    for (int v: adj[u]) {
        if (pre[v] < pre[u]) { // back edge or tree edge
            if (!pre[v]) { // tree edge
                dfs(v, u);
                low[u] = min(low[u], low[v]);
            } else { // back edge
                low[u] = min(low[u], pre[v]);
            }
        }
    }
    if (pre[u] == low[u]) {
        // process component
        comptimer++;
        while (stk.back() != u) {
            int v = stk.back();
            comp[v] = comptimer;
            stk.pop_back();
        }
        comp[u] = comptimer;
        stk.pop_back();
    }
    pre[u] = inf;
}

void form_compadj() {
    for (int u = 1; u <= 2 * m; u++) {
        for (int v: adj[u]) {
            if (comp[u] != comp[v]) {
                compadj[comp[u]].pb(comp[v]);
            }
        }
    }
    for (int i = 1; i <= comptimer; i++) {
        vector<int> & edges = compadj[i];
        sort(edges.begin(), edges.end());
        compadj[i].erase(unique(edges.begin(), edges.end()), edges.end());
    }
}

void clean_adj() {
    for (int i = 1; i <= 2 * n; i++) {
        vector<int> &edges = adj[i];
        sort(edges.begin(), edges.end());
        edges.erase(unique(edges.begin(), edges.end()), edges.end());
    }
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    for (int u = 1; u <= n; u++) {
        if (!pre[u]) dfs(u, u);
    }
    form_compadj();
    
}

// Alternate impl??

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
const int inf = 1e18;

int t;

int n, m;

const int maxn = 2e5 + 5;
vector<pi> adj[maxn];
int low[maxn], pre[maxn], comp[maxn];
int was[maxn];
bool onstk[maxn];
int timer = 0;
int comptimer = 0;
vector<int> stk;

int cyc[maxn];
int gcds[maxn];
int depth[maxn];

void dfs1(int u, int p) {
    pre[u] = low[u] = ++timer;
    onstk[u] = true;
    stk.pb(u);
    for (auto [v, w]: adj[u]) {
        if (was[v]) {
            if (onstk[v]) {
                // back(stack?) edge
                low[u] = min(low[u], pre[v]);
                int len = depth[u] - depth[v] + w;
            }
            continue;
        }
        was[v] = true;
        depth[v] = depth[u] + w;
        dfs1(v, u);
        low[u] = min(low[u], low[v]);
    }
    if (pre[u] == low[u]) {
        // process component
        comptimer++;
        while (stk.back() != u) {
            int v = stk.back();
            comp[v] = comptimer;
            onstk[v] = false;
            stk.pop_back();
        }
        comp[u] = comptimer;
        onstk[u] = false;
        stk.pop_back();
    }
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    for (int i = 1; i <= n; i++) if (!was[i]) was[i] = true, dfs1(i, i);
    for (int i = 1; i <= n; i++) {
        int col = comp[i];
        gcds[col] = __gcd(gcds[col], cyc[i]);
    }

    int q;
    cin >> q;
    while (q--) {
        int u, st, tot;
        cin >> u >> st >> tot;
        int tar = (tot - st) % tot;
        int gcd_val = gcds[comp[u]];
        // cout << "u: " << u << ", gcd_val: " << gcd_val << ", tar: " << tar << "\n";
        // goal: attain tar % tot
        if (tar == 0) {
            cout << "YES\n";
        } else if (gcd_val == 0) {
            cout << "NO\n";
        } else {
            int min_possible = __gcd(gcd_val, tot);
            if (tar % min_possible == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

} 