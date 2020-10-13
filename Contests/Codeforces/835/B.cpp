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



int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    int k;
    string st;
    cin >> k >> st;
    vector<pi> margins;
    int n = st.size();
    // int a1 = st[n - 1] - '1';
    // int a2 = '9' - st[n - 1];
    // margins.pb(mp(max(a1, a2), min(a1, a2)));
    // for (int i = n - 2; i >= 0; i--) {
    //     int a1 = st[i] - '0';
    //     int a2 = '9' - st[i];
    //     margins.pb(mp(max(a1, a2), min(a1, a2)));
    // }
    // sort(margins.begin(), margins.end());
    // int tot = 0;
    // int ans = 0;
    // while (tot < k) {
    //     int val = margins.back().f;
    //     margins.pop_back();
    //     tot += val;
    //     ans++;
    // }
    // cout << ans << "\n";
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += st[i] - '0';
    }
    vector<int> increment;
    for (int i = 0; i < n; i++) {
        increment.pb('9' - st[i]);
    }
    int need_add = max(0LL, k - total_sum);
    sort(all(increment));
    int tot = 0;
    int ans = 0;
    while (tot < need_add) {
        int a = increment.back();
        increment.pop_back();
        tot += a;
        ans++;
    }
    cout << ans << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/