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
int a, b, c, d;

int tri(int n) {
    return (n) * (n + 1) / 2;
}

int calc(int opt_i) {
    return (opt_i + 1) * a - d * b * tri(opt_i);
}

bool valid(int cand, int max_i) {
    if (cand > max_i) return false;
    return calc(cand) >= calc(cand - 1);
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;

        if (a <= b) {
            cout << a << "\n";
            continue;
        }

        if (a > c * b) {
            cout << -1 << "\n";
            continue;
        }

        int ans = a;
        int cumul = 0;
        //find the last i where (i + 1) * a  >= cumul
        int max_i = c / d;
        int ln = 20;
        int opt_i = 0;
        for (int i = ln; i >= 0; i--) {
            int cand = opt_i | (1 << i);
            if (valid(cand, max_i)) {
                opt_i = cand;
            }
        }
        ans = max(ans, calc(opt_i));
        // for (int i = 0; i * d <= c; i++) {
        //     cumul += i * d * b; // cumul = d * b * tri(i)
        //     ans = max(ans, (i + 1) * a - cumul);
        // }
        cout << ans << "\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/