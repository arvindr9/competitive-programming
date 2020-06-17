/*
Supports the following
- Add a value to a path in a tree
- Query the value at each point
Source: USACO December 2015 Platinum -- Max Flow
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

const int maxn = 1e5 + 5;
vector<int> adj[maxn];
const int ln = 16;
int n, k;
int anc[maxn][ln + 1], tin[maxn], tout[maxn], bit[maxn], depth[maxn];
int timer = 1;

void dfs(int u, int p) {
    anc[u][0] = p;
    tin[u] = timer++;
    for (int i = 1; i <= ln; i++) {
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    }
    for (int v: adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    tout[u] = timer++;
}

inline int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = ln; i >= 0; i--) {
        if ((depth[u] - (1 << i)) >= depth[v]) u = anc[u][i];
    }
    if (u == v) return u;
    for (int i = ln; i >= 0; i--) {
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
}

void update(int pos, int delta) {
    for (int i = pos; i <= timer; i += i & -i) {
        bit[i] += delta;
    }
}

int get(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        res += bit[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 1);
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        if (tin[v] < tin[u]) swap(u, v);
        int l = lca(u, v);
        // cout << "u: " << u << ", v: " << v << ", l: " << l << "\n";
        update(tin[u], +1);
        update(tin[v], +1);
        update(tout[l], -1);
        update(tin[l], -1);
        int l2 = v;
    }
    int ans = get(1);
    for (int i = 2; i <= n; i++) {
        ans = max(ans, get(tout[i] - 1) - get(tin[i] - 1));
    }
    // for (int i = 1; i <= n; i++) {
    // cout << "i: " << i << ", i flow: " << get(tout[i] - 1) - get(tin[i] - 1) << "\n";
    // }
    cout << ans << "\n";

}
