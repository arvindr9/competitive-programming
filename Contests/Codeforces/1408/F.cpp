// Upsolved after contest

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

const int maxn = 15005;
int t;
vector<pi> pairs;

void construct(int l, int pw) {
    if (pw > 1) {
        construct(l, pw / 2);
        construct(l + pw / 2, pw / 2);
    }
    for (int i = 1; i <= (int)(pw / 2); i++) {
        pairs.pb({l + i, l + (pw / 2) + i});
    }
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int max_pow = 1;
    while (max_pow * 2 <= n) max_pow *= 2;
    construct(0, max_pow);
    construct(n - max_pow, max_pow);
    cout << pairs.size() << "\n";
    for (pi p: pairs) {
        cout << p.f << " " << p.s << "\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/