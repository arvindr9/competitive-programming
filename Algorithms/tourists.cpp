#include <bits/stdc++.h>

using namespace std;
const int MAXN = 200050;
const int LN = 20;
vector<int> adj[MAXN];
int depth[MAXN], anc[LN][MAXN];
int n;

void dfs(int u, int p = 1) {
    anc[0][u] = p;
    for(int i = 1; i < LN; i++) {
        anc[i][u] = anc[i-1][anc[i-1][u]];
    }
    for(int v: adj[u]) {
        if(v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) {
        swap(u, v);
    }
    for(int i = LN - 1; i >= 0; i--) {
        if(depth[u] - (1 << i) >= depth[v]) {
            u = anc[i][u];
        }
    }
    if(u == v) {
        return u;
    }
    for(int i = LN - 1; i >= 0; i--) {
        if(anc[i][u] != anc[i][v]) {
            u = anc[i][u];
            v = anc[i][v];
        }
    }
    return anc[0][u];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)] + 1;
}


int main() {
    cin >> n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 2 * i; j <= n; j += i) {
            ans += dist(i, j);
        }
    }
    cout << ans << "\n";
}