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

const int maxn = 1e5 + 5;

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
        if (v != p) {
            if (pre[v] < pre[u]) { // back edge or tree edge
                if (!pre[v]) { // tree edge
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                } else { // back edge
                    low[u] = min(low[u], pre[v]);
                }
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
    for (int u = 1; u <= n; u++) {
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