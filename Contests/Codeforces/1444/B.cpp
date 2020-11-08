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
const ll mod = 998244353;
const int maxp = 1e6 + 5;

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
int fact[maxp];

inline int binom(int a, int b) {
    if (b > a) return 0;
    int num = fact[a];
    int den = prod(fact[b], fact[a - b]);
    return prod(num, inv(den));
}

inline int cayley(int num, int s) {
    if (num == s) return 1;
    int a1 = modpow(num, num - s - 1);
    return prod(s, a1);
}

void process_fac() {
  fact[0] = 1;
  for (int i = 1; i < maxp; i++) {
    fact[i] = prod(fact[i - 1], i);
  }
}



int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    int n;
    cin >> n;
    process_fac();
    vector<int> inp(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> inp[i];
    }
    sort(all(inp));
    int a1 = 0;
    for (int i = 0; i < n; i++) {
        a1 += (inp[i + n] - inp[i]);
    }
    a1 = reduce(a1);
    int ans = prod(a1, binom(2 * n, n));
    cout << ans << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/