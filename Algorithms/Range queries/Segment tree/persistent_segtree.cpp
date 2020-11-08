// used in https://codeforces.com/contest/1422/submission/97913858

struct big_node {
    big_node *l, *r;
    int val;
    big_node(): l(nullptr), r(nullptr), val(val) {}
    big_node(int val) : l(nullptr), r(nullptr), val(val) {}
    big_node(big_node *l, big_node *r): l(l), r(r), val(1) {
        if (l) val = prod(val, l-> val);
        if (r) val = prod(val, r-> val);
    }

};

big_node* build(int tl, int tr, vector<int> &a) {
    if (tl == tr) {
        return new big_node(a[tl]);
    }
    int tm = (tl + tr) / 2;
    return new big_node(build(tl, tm, a), build(tm + 1, tr, a));
}

big_node* upd(big_node* v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        return new big_node(val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return new big_node(upd(v->l, tl, tm, pos, val), v->r);
        } else {
            return new big_node(v->l, upd(v->r, tm + 1, tr, pos, val));
        }
    }
}

int query_prod(big_node* v, int tl, int tr, int l, int r) {
    if (l > r) return 1;
    if (l == tl and r == tr) return v->val;
    int tm = (tl + tr) / 2;
    return prod(query_prod(v->l, tl, tm, l, min(tm, r)), query_prod(v->r, tm + 1, tr, max(l, tm + 1), r));
}

big_node* upd(big_node* v, int pos, int val) {
    return upd(v, 1, n, pos, val);
}

int query_prod(big_node* v, int l, int r) {
    return query_prod(v, 1, n, l, r);
}
big_node* build(vector<int> &a) {
    return build(1, n, a);
}