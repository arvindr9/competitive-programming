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
int t;
const int mod = 1e9 + 7;

int reduce(int a) {
    return ((a % mod) + mod) % mod;
}

int add(int a, int b) {
    return reduce(a + b);
}

int prod(int a, int b) {
    return reduce(a * b);
}

int binom(int a) {
    return a * (a - 1LL) / 2LL;
}

int poww10[maxn];
int pre[maxn];
string st;
int digits[maxn];


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> st;
    int n = st.size();
    poww10[0] = 1;
    for (int i = 1; i <= n; i++) {
        digits[i] = st[i - 1] - '0';
        pre[i] = pre[i - 1] + digits[i];
        poww10[i] = prod(poww10[i - 1], 10);
    }
    int ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        ans = add(ans, prod(i, prod(poww10[i - 1], pre[n - i])));
    }
    for (int i = 2; i <= n; i++) {
        ans = add(ans, prod(binom(i), prod(digits[i], poww10[n - i])));
    }
    cout << ans << "\n";

    
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/