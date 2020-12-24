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

const int maxn = 105;
int t;
int n;
int a[maxn][maxn];

void reset() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2 == 0) {
            for (int i = 0; i * 2 <= n; i++) {
                a[2 * i + 1][2 * i + 1] = a[2 * i + 2][2 * i + 2] = 1;
                a[2 * i + 1][2 * i + 2] = a[2 * i + 2][2 * i + 1] = 4;
            }
        } else {
            for (int i = 0; i * 2 < n - 1; i++) {
                a[2 * i + 1][2 * i + 1] = a[2 * i + 2][2 * i + 2] = 1;
                a[2 * i + 1][2 * i + 2] = a[2 * i + 2][2 * i + 1] = 4;
            }
            a[n][n] = a[n - 1][n - 1] = a[n - 2][n - 2] = 1;
            a[n - 2][n - 1] = a[n - 2][n] = a[n][n - 2] = a[n][n - 1] = a[n - 1][n - 2] = a[n - 1][n] = 6;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }


        reset();

    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/