/*
JOI 2013 Synchronization

Supports cutting / merging components and checking whether two components
are connected

*/
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
const ll INF = 1e18;
const int MX = 100001;

int n, m, q;
const int maxn = 1e5 + 5;
int timer = 0;
int tin[maxn], tout[maxn];
const int ln = 17;
int anc[maxn][ln + 1], x[maxn], y[maxn], state[maxn];
int original_cost[maxn], cur_cost[maxn];
int bit[maxn];
vector<int> adj[maxn];

void update(int pos, int delta) {
    for (int i = pos; i < maxn; i += i & -i) {
        bit[i] += delta;
    }
}

int get_sum(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        res += bit[i];
    }
    return res;
}

void dfs(int u, int p) {
    anc[u][0] = p;
    // if (u != 1) {
    //     update(tin[u], 1);
    //     update(tout[u], -1);
    // }
    for (int i = 1; i <= ln; i++) {
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    }
    tin[u] = timer++;
    for (int v: adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = timer;
}


int find_ancestor(int u) {
    int lca = u;
    for (int i = ln; i >= 0; i--) {
        int candidate = anc[lca][i];
        if (get_sum(tin[candidate]) == get_sum(tin[u])) {
            lca = candidate;
        }
    }
    return lca;
}

void merge(int u, int p) {
    // cout << "merging " << u << " and " << p << "\n";
    update(tin[u], -1);
    update(tout[u], 1);
    p = find_ancestor(p);
    // cout << "p: " << p << "\n";
    cur_cost[p] = cur_cost[p] + cur_cost[u] - original_cost[u];
    cur_cost[u] = original_cost[u] = 0;
}

void cut(int u, int p) {
    // cout << "cutting " << u << " and " << p << "\n";
    p = find_ancestor(p);
    original_cost[u] = cur_cost[u] = cur_cost[p];
    update(tin[u], 1);
    update(tout[u], -1);
}

int query(int u) {
    // cout << "u: " << u << ", ";
    u = find_ancestor(u);
    // cout << "ancestor: " << u << "\n";
    return cur_cost[u];
}

void print_costs() {
    for (int i = 1; i <= n; i++) {
        cout << "i: " << i << ", orig: " << original_cost[i]
        << ", cur: " << cur_cost[i] << "\n";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("sync.in", "r", stdin);
    // freopen("sync.out", "w", stdout);
    cin >> n >> m >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        x[i] = u;
        y[i] = v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        original_cost[i] = 0;
        cur_cost[i] = 1;
    }
    dfs(1, 1);
    for (int i = 1; i < n; i++) {
        if (anc[y[i]][0] == x[i]) swap(x[i], y[i]); //x[i] will be the child
        update(tin[x[i]], 1);
        update(tout[x[i]], -1);
    }
    for (int i = 1; i <= m; i++) {
        int d;
        cin >> d;
        if (state[d] == 0) {
            merge(x[d], y[d]);
        } else {
            cut(x[d], y[d]);
        }
        state[d] = 1 - state[d];
        // print_costs();
    }
    for (int i = 1; i <= q; i++) {
        int c;
        cin >> c;
        cout << query(c) << "\n";
    }
}
