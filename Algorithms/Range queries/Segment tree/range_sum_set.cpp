/*
Arvind Ramaswami
Supports range sum queries, range set updates, and range add updates
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

typedef int int2;
#define int long long

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

mt19937_64 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

const int maxn = 1e6 + 5;
int n, q;
int a[maxn], t[4 * maxn];
int ladd[maxn], lset[maxn], setting[maxn];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void push(int v, int tl, int tr) {
    int tm = (tl + tr) / 2;
    if (setting[v]) {
        setting[v] = false;
        setting[2 * v] = setting[2 * v + 1] = true;
        ladd[2 * v] = ladd[2 * v + 1] = 0;

        lset[2 * v] = lset[2 * v + 1] = lset[v];
        t[2 * v] = (lset[2 * v]) * (tm - tl + 1);
        t[2 * v + 1] = (lset[2 * v + 1]) * (tr - (tm + 1) + 1);
    } else {
        if (setting[2 * v]) {
            lset[2 * v] += ladd[v];
            t[2 * v] = (lset[2 * v]) * (tm - tl + 1);
        } else {
            ladd[2 * v] += ladd[v];
            t[2 * v] += ladd[v] * (tm - tl + 1);
        }
        if (setting[2 * v + 1]) {
            lset[2 * v + 1] += ladd[v];
            t[2 * v + 1] = (lset[2 * v + 1]) * (tr - (tm + 1) + 1);
        } else {
            ladd[2 * v + 1] += ladd[v];
            t[2 * v + 1] += ladd[v] * (tr - (tm + 1) + 1);
        }
        ladd[v] = 0;
    }
}


void update(int v, int tl, int tr, int l, int r, int type, int val) {
    if (l > r) return;
    if (l == tl and r == tr) {
        if (type == 1) { //add
            if (setting[v]) {
                lset[v] += val;
                t[v] = lset[v] * (tr - tl + 1);
            } else {
                ladd[v] += val;
                t[v] += val * (tr - tl + 1);
            }
        } else { //set
            ladd[v] = 0;
            lset[v] = val;
            setting[v] = true;
            t[v] = val * (tr - tl + 1);
        }
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(tm, r), type, val);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, type, val);
    t[v] = t[2 * v] + t[2  * v + 1];

}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl and r == tr) {
        return t[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return query(2 * v, tl, tm, l, min(tm, r)) + query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

int query(int l, int r) {
    return query(1, 1, n, l, r);
}

void update(int l, int r, int type, int val) {
    update(1, 1, n, l, r, type, val);
}



int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 3) {
            cout << query(l, r) << endl;
        } else {
            int v;
            cin >> v;
            update(l, r, type, v);
        }
    }
    
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/