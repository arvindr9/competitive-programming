//segtree lazy prop for max queries (hopefully this works, based on
//the implementation from cp-algorithms)

#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>

#include <iostream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>

// #include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;
typedef priority_queue<int, vector<int>, greater<int> > min_heap;

// template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const double PI = 4*atan(1);
const int INF = 1e10;
const int MX = 100001;

const int maxn = 2e5 + 5;
int a[maxn], t[4 * maxn], lazy[4 * maxn];

void pull(int v) {
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

void push(int v) {
    t[2 * v] += lazy[v];
    t[2 * v + 1] += lazy[v];
    lazy[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
    lazy[v] = 0;
}

void build(int v, int tl, int tr) {
    if (tl == tr) t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        pull(v);
    }
}



void update(int v, int tl, int tr, int l, int r, int delta) {
    if (l > r) return;
    if (l == tl and r == tr) {
        lazy[v] += delta;
        t[v] += delta;
    }
    int tl = (tl + tr) / 2;
    push(v);
    update(2 * v, tl, tm, l, min(tm, r), delta);
    update(2 * v + 1, tm + 1, tr, max(l, rm + 1), r, delta);
    pull(v);
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return INF;
    if (l == tl and r == tr) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(2 * v, tl, tm, l, min(r, tm)),
        query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int n;

struct lazy_segtree_sum {
    int n;
    vector<int> t;
    vector<int> ladd;
    lazy_segtree_max(int n) {
        t.resize(4 * n + 5);
        ladd.resize(4 * n + 5);
    }
    void pull(int v) {
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    void push(int v, int tl, int tr) {
        int tm = (tl + tr) / 2;
        t[2 * v] += (tm - tl + 1) * ladd[v];
        t[2 * v + 1] += (tr - tm) * ladd[v];
        ladd[2 * v] += ladd[v];
        ladd[2 * v + 1] += ladd[v];
        ladd[v] = 0;
    }

    int query_sum(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl and r == tr) return t[v];
        int tm = (tl + tr) / 2;
        push(v, tl, tr);
        return query_sum(2 * v, tl, tm, l, min(tm, r)) + query_sum(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
    }

    int update(int v, int tl, int tr, int l, int r, int delta) {
        if (l > r) return;
        if (l == tl and r == tr) {
            t[v] += (tr - tl + 1) * delta;
            ladd[v] += delta;
        } else {
            int tm = (tl + tr) / 2;
            push(v, tl, tr);
            update(2 * v, tl, tm, l, min(tm, r));
            update(2 * v + 1, tm + 1, tr, max(tm + 1, l), r)
            pull(v);
        }
    }
};

struct lazy_segtree_max {
    int n;
    vector<int> t;
    vector<int> ladd;
    lazy_segtree_max(int n) {
        t.resize(4 * n + 5);
        ladd.resize(4 * n + 5);
    }
    void pull(int v) {
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    void push(int v) {
        t[2 * v] += ladd[v];
        t[2 * v + 1] += ladd[v];
        ladd[2 * v] += ladd[v];
        ladd[2 * v + 1] += ladd[v];
        ladd[v] = 0;
    }

    int query_max(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl and r == tr) return t[v];
        int tm = (tl + tr) / 2;
        push(v);
        return max(query_max(2 * v, tl, tm, l, min(tm, r)), query_max(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
    }

    int update(int v, int tl, int tr, int l, int r, int delta) {
        if (l > r) return;
        if (l == tl and r == tr) {
            t[v] += delta;
            ladd[v] += delta;
        } else {
            int tm = (tl + tr) / 2;
            push(v);
            update(2 * v, tl, tm, l, min(tm, r));
            update(2 * v + 1, tm + 1, tr, max(tm + 1, l), r)
            pull(v);
        }
    }

    int query_max(int l, int r) {
        return query_max(1, 0, n - 1, l, r);
    }

    void update(int l, int r, int delta) {
        update(1, 0, n - 1, l, r);
    }
};

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 0, n);
    int m;
    cin >> m;


}
