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

const int maxn = 2e3 + 5;
int t;

int numright[maxn][maxn], numdown[maxn][maxn]; //number of rocks to the right / down
int dpr[maxn][maxn], dpd[maxn][maxn]; //dpr[i][j]: went to the right to get to (i, j), will go down next
int dpsufr[maxn][maxn], dpsufd[maxn][maxn]; //suffix sum

int n, m;
char a[maxn][maxn];

const int mod = 1e9 + 7;

int reduce(int a) {
    return ((a % mod) + mod) % mod;
}

int add(int a, int b) {
    return (((a + b) % mod) + mod) % mod;
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string st;
        cin >> st;
        for (int j = 1; j <= m; j++) {
            a[i][j] = st[j - 1];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            numright[i][j] = numright[i][j + 1];
            numdown[i][j] = numdown[i + 1][j];
            if (a[i][j] == 'R') {
                numright[i][j]++;
                numdown[i][j]++;
            }

            dpsufr[i][j] = dpsufr[i][j + 1];
            dpsufd[i][j] = dpsufd[i + 1][j];

            int i_min = i + 1;
            int i_max = n - numdown[i][j];
            int j_min = j + 1;
            int j_max = m - numright[i][j];
            if (a[i][j] == 'R') {
                i_max++;
                j_max++;
            }

            if (i_min <= i_max) dpr[i][j] = add(dpsufd[i_min][j], -dpsufd[i_max + 1][j]);
            if (j_min <= j_max) dpd[i][j] = add(dpsufr[i][j_min], -dpsufr[i][j_max + 1]);
            if (i == n and j == m) {
                dpr[i][j] = dpd[i][j] = 1;
            }
            dpsufd[i][j] = add(dpsufd[i + 1][j], dpd[i][j]);
            dpsufr[i][j] = add(dpsufr[i][j + 1], dpr[i][j]);
        }
    }
    int ans = add(dpr[1][1], dpd[1][1]);
    if (n == 1 and m == 1) {
        cout << 1 << "\n";
    } else {
        cout << ans << "\n";
    }

    // cout << "dpd values: \n";
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << dpd[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "dpr values: \n";
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << dpr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    // cout << "numright values: \n";
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << numright[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "numdown values: \n";
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << numdown[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/