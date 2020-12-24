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

int min_cost(vector<int> &vals) {
    int n = vals.size();
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int cand = vals[i];
        int cost = 0;
        for (int j = 0; j < n; j++) {
            cost += abs(cand - vals[j]);
        }
        ans = min(ans, cost);
    }
    return ans;
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        vector<vector<pi>> coords;
        for (int i = 1; i <= (n + 1) / 2; i++) {
            for (int j = 1; j <= (m + 1) / 2; j++) {
                vector<pi> vec;
                vec.pb(mp(i, j));
                vector<pi> candidates = {mp(n + 1 - i, j), mp(i, m + 1 - j), mp(n + 1 - i, m + 1 - j)};
                for (pi cand: candidates) {
                    if (cand != mp(i, j)) {
                        vec.pb(cand);
                    }
                }
                coords.pb(vec);
            }
        }
        int ans = 0;
        for (vector<pi> pairs: coords) {
            // cout << "pair1: " << pairs[0].f << " " << pairs[0].s << "\n";
            vector<int> vals;
            for (pi p: pairs) {
                vals.push_back(a[p.f][p.s]);
            }
            // cout << "vals sz: " << vals.size() << "\n";
             ans += min_cost(vals);
        }
        cout << ans << "\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/