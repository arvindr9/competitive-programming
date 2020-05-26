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
