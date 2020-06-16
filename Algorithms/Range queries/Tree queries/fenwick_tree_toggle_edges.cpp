/*
Supports deleting and adding edges in a Fenwick tree and finding the highest ancestor in each component
based on the solution in https://codeforces.com/blog/entry/78564
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
	
 
	
int n, m;
	
const int maxn = 1e5 + 5;
	
int bit[maxn];
	
vector<int> adj[maxn];
	
const int ln = 17;
	
int anc[maxn][ln + 1];
	
int timer = 1;
	
int tin[maxn], tout[maxn];
	
 
	
void dfs(int u, int p) {
	
    anc[u][0] = p;
	
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
	
 
	
void update(int pos, int delta) {
	
    for (int i = pos; i < maxn; i += i & -i) {
	
        bit[i] += delta;
	
    }
	
}
	
 
	
int query(int pos) {
	
    int res = 0;
	
    for (int i = pos; i > 0; i -= i & -i) {
	
        res += bit[i];
	
    }
	
    return res;
	
}
	
 
	
int find_ancestor(int u) {
	
    int lca = u;
	
    for (int i = ln; i >= 0; i--) {
	
        if (query(tin[anc[lca][i]]) == query(tin[u])) {
	
            lca = anc[lca][i];
	
        }
	
    }
	
    return lca;
	
}
	
 
	
int main() {
	
    ios::sync_with_stdio(0);
	
    cin.tie(0);
	
    freopen("disconnect.in", "r", stdin);
	
    freopen("disconnect.out", "w", stdout);
	
    cin >> n >> m;
	
    for (int i = 1; i < n; i++) {
	
        int u, v;
	
        cin >> u >> v;
	
        adj[u].pb(v);
	
        adj[v].pb(u);
	
    }
	
    dfs(1, 0);
	
 
	
    int v = 0;
	
 
	
    for (int i = 1; i <= m; i++) {
	
        int t, x, y;
	
 
	
        cin >> t >> x >> y;
	
        
	
        int a = x ^ v;
	
        int b = y ^ v;
	
 
	
        if (t == 1) {
	
            if (anc[b][0] == a) {
	
                swap(a, b); //a's parent is now b
	
            }
	
            update(tin[a], 1); //penalty when going into a
	
            update(tout[a], -1);
	
        } else {
	
            if (find_ancestor(a) == find_ancestor(b)) {
	
                cout << "YES\n";
	
                v = a;
	
            } else {
	
                cout << "NO\n";
	
                v = b;
	
            }
	
        }
	
    }
	
}
