template<class T, class F> struct segtree {
    int n;
    vector<T> t;
    T deft;
    F f; // will be min or max or something very similar
    // point update, range query
    segtree(int _n, F _f, T _deft): n(_n + 1), deft(_deft), f(_f) {
        t.resize(2 * n, deft);
    }
    void update(int p, T value) {
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = f(t[p], t[p^1]);
    }
    T query(int l, int r) {
        T res = deft;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = f(res, t[l++]);
            if (r&1) res = f(res, t[--r]);
        }
        return res;
    }
    T query(int pos) {
        return query(pos, pos);
    }
};