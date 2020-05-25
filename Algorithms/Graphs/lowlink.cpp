//implementation for finding bridges and articulation points

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

const int maxn = 2e5 + 5;
int timer = 0;
int pre[maxn], lo[maxn], visited[maxn];
vector<int> adj[maxn];

vector<pi> bridges;
int art[maxn];

void dfs(int u, int p) {
    pre[u] = ++timer;
    lo[u] = pre[u];
    visited[u] = 1;
    int cnt = 0;
    for (int v: adj[u]) {
        if (v != p) {
            if (visited[v]) {
                lo[u] = min(lo[u], pre[v]);
            } else {
                cnt++;
                dfs(v, u);
                lo[u] = min(lo[u], lo[v]);
                if (lo[v] > pre[u]) {
                    bridges.pb(mp(u, v));
                }
                if (lo[v] >= pre[u] and u != 1) {
                    art[u] = 1;
                }
            }
        }
    }
    if (u == 1 and cnt > 1) {
        art[1] = 1;
    }
}

int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 1);
    for (pi p: bridges) {
        cout << p.f << " " << p.s << "\n";
    }
    for (int i = 1; i <= n; i++) {
        cout << art[i] << "\n";
    }



}
