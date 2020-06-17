/*
Similar to update_path_query_pt (alternative solution to USACO Max Flow with HLD)
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
#include <random>
#include <numeric>

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
int parent[maxn], depth[maxn], heavy[maxn], head[maxn], pos[maxn];
int cur_pos = 1;
vector<int> adj[maxn];
int bit[maxn];

int bit_query(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        res += bit[i];
    }
    return res;
}

void bit_update(int pos, int delta) {
    for (int i = pos; i < maxn; i += i & -i) {
        bit[i] += delta;
    }
}

int dfs(int u) {
    int size = 1;
    int max_v_size = 0;
    for (int v: adj[u]) {
        if (v != parent[u]) {
            parent[v] = u;
            depth[v] = depth[u] + 1;
            int v_size = dfs(v);
            size += v_size;
            if (v_size > max_v_size) {
                max_v_size = v_size;
                heavy[u] = v;
            }
        }
    }
    return size;
}

void decompose(int u, int h) {
    head[u] = h;
    pos[u] = cur_pos++;
    if (heavy[u] != -1) {
        decompose(heavy[u], h);
    }
    for (int v: adj[u]) {
        if (v != parent[u] and v != heavy[u]) {
            decompose(v, v);
        }
    }
}


void update(int u, int v, int delta) {
    int res = 0;
    for (; head[u] != head[v]; v = parent[head[v]]) {
        if (depth[head[u]] > depth[head[v]]) swap(u, v);
        bit_update(pos[head[v]], +delta);
        bit_update(pos[v] + 1, -delta);
    }
    if (depth[u] > depth[v]) swap(u, v);
    bit_update(pos[u], +delta);
    bit_update(pos[v] + 1, -delta);
}

int n, k;



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
    for (int i = 1; i <= n; i++) {
        heavy[i] = -1;
    }
    dfs(1);
    decompose(1, 1);
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        update(u, v, +1);
    }
    int ans = 0;
    for (int i = 1; i<= cur_pos; i++) {
        ans = max(ans, bit_query(i));
    }
    cout << ans << "\n";

}
