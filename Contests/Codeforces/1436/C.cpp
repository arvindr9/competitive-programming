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
const ll mod = 1e9 + 7;
const int maxp = 1e3 + 5;

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
int fact[maxn];

void process_fac() {
  fact[0] = 1;
  for (int i = 1; i < maxp; i++) {
    fact[i] = prod(fact[i - 1], i);
  }
}


int n, x, pos;

int bin_search() {
    int num_greater = 0;
    int num_less = 0;
    int left = 0;
    int right = n;
    while (left < right) {
        int middle = (left + right) / 2;
        // cout << "left: " << left << ", right: " << right << "\n";
        if (pos == middle) {
            left = middle + 1;
            continue;
        } else if (pos > middle) {
            num_less++;
            left = middle + 1;
        } else {
            num_greater++;
            right = middle;
        }
    }
    // ans = num ways to assign greater elts * num w assign smaller elts * num rem
    // = (n - x) * (n - x - 1) ... * (n - x - greater + 1) * less! * (n - greater - less - 1)!
    // cout << "num_greater: " << num_greater << ", num_less: " << num_less << "\n";
    if (num_greater > n - x) return 0;
    if (num_less >= x) return 0;
    int ans1 = prod(fact[n - x], inv(fact[n - x - num_greater]));
    // cout << "ans1: " << ans1 << "\n";
    int ans2 = prod(fact[x - 1], inv(fact[x - 1 - num_less]));
    // cout << "x - 1: " << x - 1 << "\n";
    // cout << "ans2: " << ans2 << "\n";
    ans2 = prod(ans1, ans2);
    int ans3 = prod(ans2, fact[n - num_greater - num_less - 1]);
    return ans3;
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    process_fac();
    cin >> n >> x >> pos;
    int ans = bin_search();
    cout << ans << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/