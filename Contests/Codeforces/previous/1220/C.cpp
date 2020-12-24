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

const int maxn = 5e5 + 5;
int t;
string st;
int n;
int dp[maxn];


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> st;
    n = st.size();
    dp[0] = 0; //first player loses
    char earliest = st[0];
    // dp[i]: 1 iff exists smaller character earlier with dp = 0
    for (int i = 1; i < n; i++) {
        if (st[i] > earliest) {
            dp[i] = 1;
        } else {
            dp[i] = 0;
        }
        earliest = min(st[i], earliest);
    }
    for (int i = 0; i < n; i++) {
        if (dp[i]) {
            cout << "Ann\n";
        } else {
            cout << "Mike\n";
        }
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/