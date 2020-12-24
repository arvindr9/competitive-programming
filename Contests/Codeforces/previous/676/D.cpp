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

int n, m;
int xt, yt, xm, ym;

const int maxn = 1005;
vector<tuple<int, int, int>> adj[maxn][maxn][4];
char ops[maxn][maxn][4];
int dist[maxn][maxn][4];

map<char, char> nxt = {
    {'+','+'},
    {'-','|'},
    {'|','-'},
    {'^','>'},
    {'>','v'},
    {'v','<'},
    {'<','^'},
    {'L','U'},
    {'U','R'},
    {'R','D'},
    {'D','L'},
    {'*','*'}
};
set<char> rig = {'-','+','>','L','U','D'};
set<char> lef = {'-','+','<','R','U','D'};
set<char> up = {'|','+','^','L','R','D'};
set<char> down = {'|','+','v','L','R','U'};

vector<tuple<int, int, int>> get_neighbors(int i, int j, int k) {
    vector<tuple<int, int, int>> ans;
    ans.emplace_back(i, j, (k + 1) % 4);
    char ch = ops[i][j][k];

    if (i > 0) {
        if (up.count(ch)) {
            if (down.count(ops[i - 1][j][k])) {
                ans.emplace_back(i - 1, j, k);
            }
        }
    }
    if (i < n - 1) {
        if (down.count(ch)) {
            if (up.count(ops[i + 1][j][k])) {
                ans.emplace_back(i + 1, j, k);
            }
        }
    }
    if (j > 0) {
        if (lef.count(ch)) {
            if (rig.count(ops[i][j - 1][k])) {
                ans.emplace_back(i, j - 1, k);
            }
        }
    }

    if (j < m - 1) {
        if (rig.count(ch)) {
            if (lef.count(ops[i][j + 1][k])) {
                ans.emplace_back(i, j + 1, k);
            }
        }
    }
    return ans;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ops[i][j][0] = grid[i][j];
            dist[i][j][0] = INF;
            for (int k = 1; k < 4; k++) {
                ops[i][j][k] = nxt[ops[i][j][k - 1]];
                dist[i][j][k] = INF;
            }
        }
    }
    grid.clear();
    cin >> xt >> yt >> xm >> ym;
    xt--, yt--, xm--, ym--;

    dist[xt][yt][0] = 0;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(xt, yt, 0));
    while (!q.empty()) {
        tuple<int, int, int> tt = q.front();
        q.pop();
        int i, j, k;
        tie(i, j, k) = tt;
        for (tuple<int, int, int> tt2: get_neighbors(i, j, k)) {
            int i2, j2, k2;
            tie(i2, j2, k2) = tt2;
            if (dist[i2][j2][k2] != INF) continue;
            dist[i2][j2][k2] = dist[i][j][k] + 1;
            // cout << "i2, j2, jk: " << i2 << " " << j2 << " " << k2 << ", dist: " << dist[i2][j2][k2] << "\n";
            q.push(make_tuple(i2, j2, k2));
        }
    }

    int ans = INF;
    for (int k = 0; k < 4; k++) {
        // cout << "d: " << dist[xm][ym][k] << "\n";
        ans = min(ans, dist[xm][ym][k]);
    }
    if (ans == INF) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/