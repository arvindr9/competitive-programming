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

const int maxn = 1e5 + 5;
int n, k;
string st;
int pre[27][maxn];
int pre2[27][maxn]; // number of empty spots

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> n >> k;
    cin >> st;
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) {
            pre[i][j] = pre[i][j - 1];
            pre2[i][j] = pre2[i][j - 1] + 1;
            if (st[j - 1] - 'a' == i) {
                pre[i][j]++;
                pre2[i][j]--;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        int r = 1;
        for (int j = 1; j <= n; j++) {
            r = max(r, j - 1);
            int empty_spots = pre2[i][j - 1];
            while (r + 1 <= n and pre2[i][r + 1] - empty_spots <= k) {
                r++;
            }
            if (r < j) continue;
            if (r - j + 1 > ans) {
                // cout << "pre[r]: " << pre[i][r] << ", pre[j - 1]: " << pre[i][j - 1] << "\n";
                // cout << "pre2[r]: " << pre2[i][r] << ", pre2[j - 1]: " << pre2[i][j - 1] << "\n";
                // cout << "r: " << r << ", j: " << j << "\n";
                ans = r - j + 1;
            }
        }
    }
    cout << ans << "\n";

}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/