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
const int inf = 1e18;

template<class T> struct lazy_segtree_min {
    int n;
    T deft;
    vector<T> t, ladd;
    lazy_segtree_min(int _n): deft(0), t(4 * _n + 5), ladd(4 * _n + 5), n(_n) {}
    T f(T a, T b) {
        return min(a, b);
    }
    void pull(int v) {
        t[v] = f(t[2 * v], t[2 * v + 1]);
    }
    void push(int v) {
        t[2 * v] += ladd[v];
        t[2 * v + 1] += ladd[v];
        ladd[2 * v] += ladd[v];
        ladd[2 * v + 1] += ladd[v];
        ladd[v] = 0;
    }
    void update(int v, int tl, int tr, int l, int r, int delta) {
        if (l > r) return;
        if (l == tl and r == tr) {
            ladd[v] += delta;
            t[v] += delta;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, l, min(tm, r), delta);
            update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, delta);
            pull(v);
        }
    }
    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return deft;
        if (l == tl and r == tr) {
            return t[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        return f(query(2 * v, tl, tm, l, min(tm, r)), query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    void update(int l, int r, int delta) {
        update(1, 0, n, l, r, delta);
    }
    T query(int l, int r) {
        return query(1, 0, n, l, r);
    }
};

// historical max, untested

struct segtree {
    int n;
    vector<int> mx, best, ladd, lbest;
    segtree(int _n): n(_n + 1), mx(4*_n+5), best(4*_n+5), ladd(4*_n+5), lbest(4*_n+5) {}
    void push(int v, int w) {
        lbest[w] = max(lbest[w], ladd[w] + lbest[v]);
        ladd[w] += ladd[v];
        best[w] = max(best[w], mx[w] + lbest[v]);
        mx[w] += ladd[v];
    }
    void push(int v) {
        push(v, 2 * v);
        push(v, 2 * v + 1);
        lbest[v] = 0;
        ladd[v] = 0;
    }
    void pull(int v) {
        mx[w] = max(mx[2 * w], mx[2 * w + 1]);
        best[w] = max(best[2 * w], best[2 * w + 1]);
    }
}

