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
int t;

int a[maxn];
vector<int> adj[maxn];

tuple<int, int, int> dfs(int u, int p = 1) { // num nodes, max, sum
    int total_nodes = 0;
    int total_max = 0;
    int total_sum = 0;
    int to_add = a[u];
    for (int v: adj[u]) {
        tuple<int, int, int> t2 = dfs(v, u);
        int nodes, mx, sm;
        tie(nodes, mx, sm) = t2;
        total_max = max(mx, total_max);
        total_sum += sm;
        total_nodes += nodes;
    }
    // if (u == 1) {
    //     cout << "total sum: " << total_sum << ", total_max: " << total_max << ", total nodes: " << total_nodes << "\n";
    // }
    if (total_nodes == 0) total_nodes++;
    int to_fill = total_nodes * total_max - total_sum;
    // cout << "to_fill: " << to_fill << "\n";
    to_add -= min(to_fill, a[u]);
    if (to_add == 0) {
        return make_tuple(total_nodes, total_max, total_sum + a[u]);
    } else {
        // if ()
        total_max += (to_add + total_nodes - 1) / total_nodes;
        return make_tuple(total_nodes, total_max, total_sum + a[u]);
    }
    
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int pi;
        cin >> pi;
        adj[pi].pb(i);
    }

    for (int i = 1;i <= n; i++) {
        cin >> a[i];
    }

    tuple<int, int, int> opt = dfs(1, 1);
    int ans = get<1>(opt);
    cout << ans << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/