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

const int maxn = 1e3 + 5;
int t;
int n;
int a[maxn][maxn];

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (a % b == 0) return b;
    return gcd(b, b % a);
}



int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> n;
    int g = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int num = a[3][1];
    int den = a[3][2];
    int a1_sq = a[1][2] * num / den;
    int a1;
    for (int i = 1; i * i <= a1_sq; i++) {
        if (i * i == a1_sq) {
            a1 = i;
            break;
        }
    }
    cout << a1 << " ";
    for (int i = 2; i <= n; i++) {
        cout << a[1][i] / a1 << " ";
    }
    cout << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/