/*
Point-update range-query

Verified at https://cses.fi/problemset/task/1648
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int maxn = 1e6 + 5;

ll t[4 * maxn], a[maxn];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    } else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void update(int v, int tl, int tr, int index, int k) {
    if (tl == tr) {
        t[v] = k;
    } else {
        int tm = (tl + tr) / 2;
        if (index <= tm) {
            update(2 * v, tl, tm, index, k);
        } else {
            update(2 * v + 1, tm + 1, tr, index, k);
        }
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl and r == tr) return t[v];
    int tm = (tl + tr) / 2;
    return query(2 * v, tl, tm, l, min(r, tm)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void print_tree(int l, int r, int n) {
    cout << "printing tree:\n";
    for (int i = l; i <= r; i++) {
        cout << query(1, 1, n, i, i) << " ";
    }
    cout << "\n";
} 


// used in https://codeforces.com/contest/1422/submission/97913858
struct segtree {
    vector<small_node> t;
    int n;
 
    segtree(vector<small_node> &a) {
        n = (int)a.size() - 1;
        t.resize(4 * n + 5);
        build(1, 1, n, a);
    }
 
    void build(int v, int tl, int tr, vector<small_node> &a) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(2 * v, tl, tm, a);
            build(2 * v + 1, tm + 1, tr, a);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }
 
    small_node query_lcm(int v, int tl, int tr, int l, int r) {
        small_node res;
        if (l > r) return res;
        if (l == tl and r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return query_lcm(2 * v, tl, tm, l, min(tm, r)) + query_lcm(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }  
 
    void build(vector<small_node> &a) {
        build(1, 1, n, a);
    }
 
    int query_lcm(int l, int r) {
        small_node lc = query_lcm(1, 1, n, l, r);
        int res = 1;
        for (int i = 0; i < (int)lc.powers.size(); i++) {
            res = prod(res, modpow(small_primes[i], lc.powers[i]));
        }
        return res;
    }
 
};

struct segtree_sum {
    int n;
    vector<int> t;

    segtree(int _n) {
        n = _n;
        t.resize(4 * n + 5);
    }

    void pull(int v) {
        t[v] = t[2 * v] + t[2 * v + 1];
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (r < l) return 0;
        if (l == tl and r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, min(tm, r)) + query(2 * v + 1, tm, tr, max(l, tm + 1), r);
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(2 * v, tl, tm, pos, val);
            else update(2 * v + 1, tm + 1, tr, pos, val);
            pull(v);
        }
    }

    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 2) cout << query(1, 1, n, l, r) << "\n";
        else update(1, 1, n, l, r);
        // print_tree(1, n, n);
    }
}