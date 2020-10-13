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