

/*
based on https://cp-algorithms.com/data_structures/segment_tree.html
*/

// The below is not tested but captures the main implementation -- includes binary searching prefix sums and finding the first element >= k

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
    return sum(2 * v, tl, tm, l, min(tm, r)) + sum(2 * v + 1, tm + 1, tr, max(tm + 1, l), tr);
}

void update(int v, int tl, int tr, int index, int val) {
    if (tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl #include <vector>
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
const ll INF = 1e18;
const int MX = 100001;

const int maxn = 2e5 + 5;
int t[4 * maxn], a[maxn];
vector<pi> process;

void build(int v, int tl, int tr) {
    if (tl == tr) t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl and r == tr) return t[v];
    int tm = (tl + tr)  / 2;
    return sum(2 * v,  tl, tm, l, min(r, tm)) + sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos > tm) {
            update(2 * v + 1, tm + 1, tr, pos, val);
        } else {
            update(2 * v, tl, tm, pos, val);
        }
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int find_kth(int v, int tl, int tr, int k) { //finding the kth 1 in a 0/1 array. idea can also be used for binary searching prefix sums.
    if (k > t[v]) return -1;
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) / 2;
    if (t[v * 2] >= k) {
        return find_kth(2*v, tl, tm, k);
    } else {
        return find_kth(2*v+1, tm + 1, tr, k - t[2*v]);
    }
}

int get_first(int v, int tl, int tr, int l, int r, int x) { //assuming t stores max
    if (l > r) return -1;
    if (l == tr and r == tr) {
        if (t[v] <= x) return -1;
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        if (t[2 * v] > x) return get_first(2 * v, tl, tm, tl, tm, x);
        return get_first(2 * v + 1, tm + 1, tr, tm + 1, tr, x);

    }
    int tm = (tl + tr) / 2;
    int res = get_first(2 * v, tl, tm, l, min(tm, r), x);
    if (res != -1) return res;
    return get_first(2 * v + 1, tm + 1, tr, max(tm + 1, l), r, x);
}

int get

int tt, n; //maybe need index compression




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tt;
    while (tt--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            process.pb(mp(a[i], i));
        }
        sort(process.begin(), process.end());
        ll ans = 0;
        for (pi p: process) {
            int val = p.f;
            int ind = p.s;
            ans += sum(1, 0, n, ind + 1, n);
            // cout << "val: " << val << "ind: " << ind << "\n";
            // cout << "ans: " << ans << "\n";
            update(1, 0, n, ind, 1);
        }
        cout << ans << "\n";
        for (int i = 1; i < 4 * maxn; i++) {
            t[i] = 0;
        }
        process.clear();

    }
    
    

}
