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
const ll INF = 2e18;
const int MX = 100001;

const int maxn = 1e6 + 5;
int t;
int c1, c2, c3, c4, c5, c6;

int compute(int x) {
    if (x > 0) return c1 * x;
    else return -c4 * x;
}

int compute2(int dx, int dy) {
    int ans = 0;
    if (dx > 0) ans += dx * c6;
    else ans -= dx * c3;
    if (dy > 0) {
        ans += dy * c2;
    } else {
        ans -= dy * c5;
    }
    return ans;
}


void test() {
    vector<pi> pairs = {mp(0, 0), mp(1, 1), mp(1, 0), mp(0, 1), mp(-1, -1), mp(-1, 0), mp(0, -1)};
    for (pi p: pairs) {
        cout << "p: " << p.f << " " << p.s;
        cout << "compute: " << compute2(p.f, p.s) << "\n";
    }
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
        int ans = INF;
        // test();
        ans = min(ans, compute2(x, y));
        int cand = compute(x) + compute2(0, y - x);
        if (cand >= 0) {
            ans = min(ans, cand);
        }
        cand = compute(y) + compute2(x - y, 0);
        if (cand >= 0) {
            ans = min(ans, cand);
        }
        cout << ans << "\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/