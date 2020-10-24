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

vector<int> adj[maxn];
vector<int> compadj[maxn];
int sz[maxn], dp[maxn], val[maxn], maxval[maxn];
int one[maxn];
int max_one_ans = 0;
set<pi> bridges;

int n, m;
int ss;
int a[maxn];
int visited[maxn];
int pre[maxn], low[maxn], comp[maxn];
int timer = 1;
int curcomp = 0;

void dfs(int u, int p) {
    // cout << "u: " <<  u << ", p: " << p << "\n";
    pre[u] = low[u] = timer++;
    // cout << "pre[u]: " << pre[u] << "\n";
    for (int v: adj[u]) {
        if (v != p) {
            if (pre[v] and pre[v] < pre[u]) { // back edge
                low[u] = min(low[u], pre[v]);
            } else { //downward edge
                if (!pre[v]) {
                    // cout << "u: " << u << ", v: " << v << "\n";
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                    if (low[v] == pre[v]) {
                        bridges.insert({u, v});
                    }
                }
            }
        }
    }
    // cout << "u: " << u << ", pre: " << pre[u] << ", low: " << low[u] << "\n";
}

void dfs2(int u) {
    if (visited[u]) return;
    visited[u] = true;
    comp[u] = curcomp;
    val[curcomp] += a[u];
    sz[curcomp]++;
    for (int v: adj[u]) {
        if (!visited[v]) {
            if (!(bridges.count({u, v}) or bridges.count({v,u}))) {
                dfs2(v);
            }
        }
    }
}

void dfs3(int u, int p) {
    one[u] = true;
    for (int v: compadj[u]) {
        if (v != p) {
            dfs3(v, u);
            if (!one[v]) {
                one[u] = false;
            }
        }
    }
    if (sz[u] > 1) one[u] = false;
    if (one[u]) {
        maxval[u] = val[u];
        for (int v: compadj[u]) {
            if (v != p) {
                maxval[u] = max(maxval[u], val[u] + maxval[v]);
            }
        }
        max_one_ans = max(max_one_ans, maxval[u]);
    }
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    cin >> ss;

    dfs(ss, ss);

    if (!visited[ss]) {
        curcomp++;
        dfs2(ss);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            curcomp++;
            dfs2(i);
        }
    }

    // cout << "curcomp: " << curcomp << "\n";
    // for (int i = 1; i <= curcomp; i++) {
    //     cout << sz[i] << "\n";
    // }
    for (pi bridge: bridges) {
        compadj[comp[bridge.f]].pb(comp[bridge.s]);
        compadj[comp[bridge.s]].pb(comp[bridge.f]);
    }

    dfs3(comp[ss],comp[ss]);

    // cout << "bridges:\n";
    // for (pi p: bridges) {
    //     cout << p.f << " " << p.s << "\n";
    // }

    int ans = 0;
    for (int i = 1; i <= curcomp; i++) {
        if (!one[i]) ans += val[i];
    }
    ans += max_one_ans;
    cout << ans << "\n";


}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/