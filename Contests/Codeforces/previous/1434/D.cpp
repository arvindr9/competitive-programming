// Problem link: https://codeforces.com/contest/1434/problem/D

#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define f first
#define s second


struct node {
    int d0, d1, par;
    node(): d0(-1), d1(-1), par(par) {}
    node(int depth, int par)  {
        this->par = par;
        if (par == 0) {
            d0 = depth;
            d1 = -1;
        } else {
            d0 = -1;
            d1 = depth;
        }
    }
    node(int d0, int d1, int par): d0(d0), d1(d1), par(par) {}


    friend ostream& operator<<(ostream &os, node a) {
        return os << '(' << a.d0 << ", " << a.d1 << ", " << a.par << ')';
    }

    friend node operator+(const node& a, const node& b) {
        node c;
        c.par = min(a.par, b.par);
        c.d0 = max(a.d0, b.d0);
        c.d1 = max(a.d1, b.d1);
        return c;
    }

    node flip() {
        node c;
        c.d0 = d1;
        c.d1 = d0;
        c.par = (par ^ 1);
        return c;
    }

    node operator +=(const node&b) {
        (*this) = (*this) + b;
        return *this;
    }
};


const int maxn = 5e5 + 5;
int tin[maxn], tout[maxn];
int depth[maxn];
int timer = 0;
int max_depth = -1;
int farthest;

int n, m;


node t[4 * maxn];
int lflip[4 * maxn];
node flattened[maxn];

vector<pi> adj[maxn];

void pull(int v) {
    t[v] = t[2 * v] + t[2 * v + 1];
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = flattened[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        pull(v);
    }
}

void push(int v) {
    lflip[2 * v] ^= lflip[v];
    lflip[2 * v + 1] ^= lflip[v];
    if (lflip[v]) {
        t[2 * v] = t[2 * v].flip();
        t[2 * v + 1] = t[2 * v + 1].flip();
    }
    lflip[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, int delta) {
    if (l > r) return;
    if (l == tl and r == tr) {
        if (delta == 1) {
            t[v] = t[v].flip();
            lflip[v] ^= delta;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    push(v);
    add(2 * v, tl, tm, l, min(tm, r), delta);
    add(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, delta);
    pull(v);
}

node query(int v, int tl, int tr, int l, int r) {
    if (l > r) return node(-1, -1, 1);
    if (l == tl and r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    push(v);
    return query(2 * v, tl, tm, l, min(tm, r)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void dfs(int u, int p, int par) {
    tin[u] = ++timer;
    if (depth[u] > max_depth) {
        max_depth = depth[u];
        farthest = u;
    }
    flattened[timer] = node(depth[u], par);
    for (pi nei: adj[u]) {
        int v = nei.f;
        if (v != p) {
            depth[v] = depth[u] + 1;
            int type = nei.s;
            if (type == 0) {
                dfs(v, u, par);
            } else {
                dfs(v, u, 1 - par);
            }
        }
    }
    tout[u] = timer;
}

void reset() {
    timer = 0;
    max_depth = -1;
    for (int i = 0; i < maxn; i++) {
        depth[i] = 0;
    }
    for (int i = 0; i < 4 * maxn; i++) {
        lflip[i] = 0;
    }
}

void search(int u) {
    reset();
    dfs(u, u, 0);
}

void build() {
    build(1, 1, n);
}

void toggle(pi p) {
    int u = p.f;
    int v = p.s;
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    //u will be deeper than v
    add(1, 1, n, tin[u], tout[u], 1);
}

int query_longest() {
    node opt = query(1, 1, n, 1, n);
    return opt.d0;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<pi> edges(n);
    for (int i = 1; i < n; i++) {
        int u, v, type;
        cin >> u >> v >> type;
        adj[u].eb(v, type);
        adj[v].eb(u, type);
        edges[i] = mp(u, v);
    }
    cin >> m;
    vector<int> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }
    search(1);
    vector<int> ans(m);
    int v1 = farthest;
    search(v1);
    build();
    for (int qq = 0; qq < m; qq++) {
        int e_idx = queries[qq];
        pi edge = edges[e_idx];
        toggle(edge);
        int longest_path = query_longest();
        ans[qq] = longest_path;
    }
    int v2 = farthest;
    search(v2);
    build();
    for (int qq = 0; qq < m; qq++) {
        int e_idx = queries[qq];
        toggle(edges[e_idx]);
        int longest_path = query_longest();
        ans[qq] = max(ans[qq], longest_path);
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
}