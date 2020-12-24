// 901 C (finally -- after reading the problem correctly)
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

struct lazyseg_sum {
    int n;
    vector<int> t;
    vector<int> ladd;
    lazyseg_sum(int _n) {
        n = _n;
        t.resize(4 * n + 5);
        ladd.resize(4 * n + 5);
    }
    void pull(int v) {
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    void push(int v, int tl, int tr) {
        int tm = (tl + tr) / 2;
        t[2 * v] += (tm - tl + 1) * ladd[v], t[2 * v + 1] += (tr - tm) * ladd[v];
        ladd[2 * v] += ladd[v], ladd[2 * v + 1] += ladd[v], ladd[v] = 0;
    }
    void update(int v, int tl, int tr, int l, int r, int delta) {
        if (l > r) return;
        if (l == tl and r == tr) {
            ladd[v] += delta, t[v] += (tr - tl + 1) * delta;
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(tm, r), delta), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, delta);
        pull(v);
    }
    int query_sum(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl and r == tr) return t[v];
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return query_sum(2 * v, tl, tm, l, min(r, tm)) + query_sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int l, int r, int delta) {
        // cout << "updating l: " << l << ", r: " << r << ", delta: " << delta << "\n";
        update(1, 1, n, l, r, delta);
    }

    int query_sum(int l, int r) {
        // cout << "querying l: " << l << ", r: " << r << "\n";
        int ans = query_sum(1, 1, n, l, r);
        // cout << "ans: " << ans << "\n";
        return ans;
    }
};


const int maxn = 3e5 + 5;

int n, m;

vector<int> adj[maxn];
int par[maxn];
int timer = 0;
int pre[maxn];

vector<pi> cycles;

void process_cycle(int u, int v) {
    // v is an ancestor of u
    int minv = min(u, v), maxv = max(u, v);
    while (u != v) {
        int nxt = par[u];
        minv = min(minv, u);
        maxv = max(maxv, u);
        u =  nxt;
    }
    cycles.eb(minv, maxv);
}

void dfs(int u, int p) {
    pre[u] = ++timer;
    for (int v: adj[u]) {
        if (v != p) {
            // cout << "u: " << u << ", v: " << v << ", p: " << p <<  "\n";
            if (pre[v] and pre[v] < pre[u]) {
                // process cycle
                // cout << "u: " << u << ", v: " << v << "\n";
                process_cycle(u, v);
            } else if (!pre[v]) {
                par[v] = u;
                dfs(v, u);
            }
        }
    }
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!pre[i]) dfs(i, i);
    }
    map<int, int> l2r;
    set<int> rs;
    for (auto &[l, r]: cycles) {
        l2r[l] = r;
        rs.insert(r);
    }
    vector<int> last_possible;
    for (int i = 1; i <= n; i++) {
        auto it = rs.begin();
        if (it == rs.end()) {
            last_possible.pb(n);
        } else {
            last_possible.pb((*it) - 1);
        }
        if (l2r.count(i)) {
            rs.erase(l2r[i]);
        }
    }
    lazyseg_sum tree(n);
    int q;
    cin >> q;
    vector<array<int, 3>> queries;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        queries.pb({l, r, i});
    }
    sort(queries.begin(), queries.end(), [&](auto u, auto v) {return u[0] > v[0];});

    vector<int> ans(q + 1);

    for (int l = n, i = 0; i < q; i++) {
        array<int, 3> arr = queries[i];
        int ll = arr[0], rr = arr[1], idx = arr[2];
        while (l >= ll) {
            int r = last_possible[l - 1];
            tree.update(l, r, +1);
            l--;
        }
        ans[idx] = tree.query_sum(ll, rr);
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << "\n";
    }
}