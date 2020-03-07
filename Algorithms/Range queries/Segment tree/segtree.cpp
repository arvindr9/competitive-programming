#include <bits/stdc++.h>

using namespace std;

const int maxn = (1 << 17);

/*
based on https://cp-algorithms.com/data_structures/segment_tree.html
*/

// The below is not tested but captures the main implementation

int t[4 * maxn], a[maxn];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int m = (tl + tr) / 2;
        build(2 * v, tl, m);
        build(2 * v + 1, m + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void sum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(2 * v, tl, tm, l, min(tm, r)) + sum(2 * b + 1, tm + 1, tr, max(tm + 1, l), tr);
}

void update(int v, int tl, int tr, int index, int val) {
    if (tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (index <= tm) {
            update(2 * v, tl, tm, index, val);
        } else {
            update(2 * v + 1, tm + 1, tr, index, val);
        }
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
