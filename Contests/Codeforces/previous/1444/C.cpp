#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>
typedef int int2;
#define int long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define eb emplace_back

struct dsu_rollback {
    vector<int> p;
    vector<pi> log;
    dsu_rollback(int n): p(n, -1) {}
    int root(int u) {
        return p[u] < 0 ? u : root(p[u]);
    }
    bool share(int u, int v) {
        return root(u) == root(v);
    }
    bool merge(int u, int v) {
        u = root(u);
        v = root(v);
        if (u == v) return false;
        if (p[u] > p[v]) swap(u, v);
        log.eb(v, p[v]);
        p[u] += p[v];
        p[v] = u;
        return true;
    }
    int time() {
        return (int)log.size();
    }
    void rollback(int t = 0) {
        for (int i = time() - 1; i >= t; i--) {
            auto [v, pv] = log.back();
            log.pop_back();
            int u = p[v];
            p[u] -= pv;
            p[v] = pv;
        }
    }
};

const int maxn = 5e5 + 5;
int n, m, k;
int g[maxn];
int bad[maxn];

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
    }
    vector<pi> edges;
    dsu_rollback dsu(2 * n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (g[u] > g[v]) swap(u, v);
        if (g[u] == g[v]) {
            dsu.merge(u, v + n);
            dsu.merge(v, u + n);
            if (dsu.share(u, u + n)) bad[g[u]] = true;
        } else {
            edges.eb(u, v);
        }
    }
    edges.erase(remove_if(edges.begin(), edges.end(), [&](auto e) {return bad[g[e.f]] or bad[g[e.s]];} ), edges.end());
    sort(edges.begin(), edges.end(), [&](auto e1, auto e2) {return mp(g[e1.f], g[e1.s]) < mp(g[e2.f], g[e2.s]);});

    m = edges.size();

    vector<pi> bad_pairs;

    for (int i = 0, j = 0, ti = dsu.time(); j < m; ) {
        if (j > m) break;
        int u = edges[i].f;
        int v = edges[i].s;
        int gu = g[edges[i].f];
        int gv = g[edges[i].s];
        while (j < m and mp(gu, gv) == mp(g[edges[j].f], g[edges[j].s])) {
            int u2 =  edges[j].f;
            int v2 = edges[j].s;
            dsu.merge(u2, v2 + n);
            dsu.merge(v2, u2 + n);
            if (dsu.share(u2, u2 + n)) {
                bad_pairs.eb(gu, gv);
            }
            j++;
        }
        i = j;
        dsu.rollback(ti);
    }
    bad_pairs.erase(unique(bad_pairs.begin(), bad_pairs.end()), bad_pairs.end());
    int good_groups = 0;
    for (int i = 1; i <= k; i++) {
        if (!bad[i]) good_groups++;
    }
    int num_bad = bad_pairs.size();
    int ans = (good_groups) * (good_groups - 1) / 2LL;
    ans -= num_bad;
    cout << ans << "\n";
}
