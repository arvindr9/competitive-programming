// Used for CF 876 F: https://codeforces.com/contest/876/submission/101593626

// last_leq: finds maximal r such that query(l, r) <= bound
// first_leq: finds minimal l such that query(l, r) <= bound

int last_leq(int v, int tl, int tr, int l, int r, int bound, int &accum) {
    if (l > r) return -1;

    if (l == tl and r == tr) {
        if ((accum | t[v]) <= bound) {
            accum |= t[v];
            return r;
        }
        else {
            // check largest prefix that satisfies the bound
            if (tl == tr) {
                return -1;
            } else {
                int tm = (tl + tr) / 2;
                int rr = min(r, tm);
                int ll = max(l, tm + 1);
                int res = -1;

                res = last_leq(2 * v, tl, tm, l, rr, bound, accum);
                if (res < rr) return res;

                res = max(res, last_leq(2 * v + 1, tm + 1, tr, ll, r, bound, accum));
                return res;
            }
        }
    }

    int tm = (tl + tr) / 2;
    int rr = min(tm, r);
    int ll = max(l, tm + 1);

    int res = -1;

    if (tm >= l) {
        res = last_leq(2 * v, tl, tm, l, rr, bound, accum);
        if (res < rr) return res;
    }
    res = max(res, last_leq(2 * v + 1, tm + 1, tr, ll, r, bound, accum));
    return res;
}

int first_leq(int v, int tl, int tr, int l, int r, int bound, int &accum) {
    if (l > r) return inf;

    if (l == tl and r == tr) {
        if ((accum | t[v]) <= bound) {
            accum |= t[v];
            return l;
        }
        else {
            // check largest prefix that satisfies the bound
            if (tl == tr) {
                return inf;
            } else {
                int tm = (tl + tr) / 2;
                int rr = min(r, tm);
                int ll = max(l, tm + 1);
                int res = inf;

                res = first_leq(2 * v + 1, tm + 1, tr, ll, r, bound, accum);
                if (res > ll) return res;

                res = min(res, first_leq(2 * v, tl, tm, l, rr, bound, accum));
                return res;
            }
        }
    }

    int tm = (tl + tr) / 2;
    int rr = min(tm, r);
    int ll = max(l, tm + 1);

    int res = inf;

    if (tm + 1 <= r) {
        res = first_leq(2 * v + 1, tm + 1, tr, ll, r, bound, accum);
        if (res > ll) return res;
    }
    res = min(res, first_leq(2 * v, tl, tm, l, rr, bound, accum));
    return res;
}

int last_leq(int l, int r, int bound) {
    int accum = 0;
    int res = last_leq(1, 1, n, l, r, bound, accum);
    return res;
}

int first_leq(int l, int r, int bound) {
    int accum = 0;
    int res = first_leq(1, 1, n, l, r, bound, accum);
    return res;
}