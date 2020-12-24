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



int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        m = n;
        vector<vector<char>> grid(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= n; i++) {
            string st;
            cin >> st;
            for (int j = 1; j <= m; j++) {
                grid[i][j] = st[j - 1];
            }
        }
        // cout << "grid: " << grid[2][1] << "\n";
        int a1 = grid[1][2] - '0';
        int a2 = grid[2][1] - '0';
        int b1 = grid[n][m - 1] - '0';
        int b2 = grid[n - 1][m] - '0';
        vector<pi> ans;
        // cout << a1 << " " << a2 << " " << b1 << " " << b2 << "\n"; 
        if (a1 + a2 == 0) {
            if (b1 == 0) {
                ans.pb({n, m - 1});
            }
            if (b2 == 0) {
                ans.pb({n - 1, m});
            }
        } else if (b1 + b2 == 0) {
            if (a1 == 0) {
                ans.pb({1, 2});
            }
            if (a2 == 0) {
                ans.pb({2, 1});
            }
        } else if (a1 + a2 == 2) {
            if (b1 == 1) {
                ans.pb({n, m - 1});
            }
            if (b2 == 1) {
                ans.pb({n - 1, m});
            }
        } else if (b1 + b2 == 2) {
            if (a1 == 1) {
                ans.pb({1, 2});
            }
            if (a2 == 1) {
                ans.pb({2, 1});
            }
        } else {
            if (a1 == 1) {
                ans.pb({1, 2});
            }
            if (a2 == 1) {
                ans.pb({2, 1});
            }
            if (b1 == 0) {
                ans.pb({n, m - 1});
            }
            if (b2 == 0) {
                ans.pb({n - 1, m});
            }
        }
        cout << ans.size() << "\n";
        for (pi p: ans) {
            cout << p.f << " " << p.s << "\n";
        }
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/