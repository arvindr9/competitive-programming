// Source: https://codeforces.com/contest/1444/submission/97383887

struct dsu_rollback {
    vector<int> p;
    vector<pi> log;
    dsu_rollback(int n): p(n + 1, -1) {}
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