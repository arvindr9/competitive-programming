// generic segtree
template <class T> struct segtree {
    vector<T> t;
    int n;
    T deft;
    segtree(int n): t(4 * n + 5), n(n), deft(make_pair(0LL, 0LL)) {}
    T f(T a, T b) {
        if (a.f == b.f) {
            if (a.s < b.s) return a;
            else return b;
        }
        return max(a, b);
    }
    void pull(int v) {
        t[v] = f(t[2 * v], t[2 * v + 1]);
    }
    void update(int v, int tl, int tr, int pos, T val) {
        if (tl == tr) {
            t[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(2 * v, tl, tm, pos, val);
            else update(2 * v + 1, tm + 1, tr, pos, val);
            pull(v);
        }
    }

    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return deft;
        if (l == tl and r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return f(query(2 * v, tl, tm, l, min(tm, r)), query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
    }

    void update(int pos, T val) {
        update(1, 0, n, pos, val);
    }

    T query(int l, int r) {
        return query(1, 0, n, l, r);
    }
};