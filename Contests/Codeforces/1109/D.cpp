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

int n, m, a, b;

const int mod = 1e9 + 7;


inline int reduce(int a) {
    return (a %= mod) < 0 ? a + mod : a;
}

inline int add(int a, int b) {
    return reduce(a + b);
}

inline int prod(int a, int b) {
    return reduce(a * b);
}

inline int modpow(int a, int pw) {
    if (pw == 0) return 1;
    if (pw % 2 == 0) {
        int res = modpow(a, pw / 2);
        return prod(res, res);
    }
    return prod(a, modpow(a, pw - 1));
}

inline int inv(int a) {
    return modpow(a, mod - 2);
}
int fac[maxn];

inline int binom(int a, int b) {
    int num = fac[a];
    int den = prod(fac[b], fac[a - b]);
    return prod(num, inv(den));
}

inline int cayley(int num, int s) {
    if (num == s) return 1;
    int a1 = modpow(num, num - s - 1);
    return prod(s, a1);
}

// 1109 D

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    fac[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fac[i] = prod(fac[i - 1], i);
    }

    cin >> n >> m >> a >> b;
    int ans = 0;

    for (int d = 1; d <= min(n - 1, m); d++) {
        int cur_ans = 1;
        // o---o---o----o---o----o <- d edges, d + 1 vertices
        // times (m choose d - 1)
        cur_ans = prod(cur_ans, binom(m - 1, d - 1)); //choose edge weights (d edges summing to m)
        // cout << "edge weights between: " << binom(m, d - 1) << "\n";
        // cout << "n - 2: " << n - 2 << ", n - d: " << n - d << "\n";
        cur_ans = prod(cur_ans, prod(fac[n - 2], inv(fac[n - d - 1]))); //choose representative nodes (order d - 2 nodes from n - 2 total = (n - 2)! / (n - d - 1)!)
        // cout << "rep_node ways: " << cur_ans << "\n";
        // // n - (d + 1) edges
        // cout << "n: " << n << ", d + 1: " << d + 1 << "\n";
        cur_ans = prod(cur_ans, cayley(n, d + 1)); //choose structure of trees
        cur_ans = prod(cur_ans, modpow(m, n - (d + 1))); //choose edge weights
        // cout << "cur_ans: " << cur_ans << "\n";
        ans = add(ans, cur_ans);
    }

    cout << ans << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/