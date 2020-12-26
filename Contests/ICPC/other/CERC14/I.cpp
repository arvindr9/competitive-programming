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

int num_intersections(pi dir, pair<pi, pi> seg) {
    int x1 = seg.f.f;
    int y1 = seg.f.s;
    int x2 = seg.s.f;
    int y2 = seg.s.s;
    // true if x1 / y1 <= dir <= x2 / y2
    if (min(dir.f, dir.s) == 0) return max(x2 - x1 + 1, y2 - y1 + 1);
    // now there will be at most one intersection
    if (x1 == x2) { // vertical
        // want x * diry / dirx to be an integer in the range
        if ((x1 * dir.s) % dir.f == 0) {
            int ycand = x1 * dir.s / dir.f;
            if (y1 <= ycand and ycand <= y2) {
                return 1;
            }
        }
        return 0;
    }
    if (y1 == y2) { // horizontal
        if ((y1 * dir.f) % dir.s == 0) {
            int xcand = y1 * dir.f / dir.s;
            if (x1 <= xcand and xcand <= x2) {
                return 1;
            }
        }
        return 0;
    }
    return 0;
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> t;
    while (t--) {
        vector<pair<pi, pi>> segments;
        int n;
        cin >> n;
        int curx = 0;
        int cury = 0;
        for (int i = 1; i <= n; i++) {
            int j; char ch;
            cin >> j >> ch;
            if (ch == 'B') {
                segments.pb(mp(mp(curx + 1, cury), mp(curx + j, cury)));
                curx += j;
            } else {
                segments.pb(mp(mp(curx, cury + 1), mp(curx, cury + j)));
                cury += j;
            }
        }
        int g = __gcd(curx, cury);
        curx /= g;
        cury /= g;
        pi dir = mp(curx, cury);
        int ans = 0;
        // cout << "dir: " << dir.f << " " << dir.s << "\n";
        for (int i = 0; i < n; i++) {
            ans += num_intersections(dir, segments[i]);
            // cout << "p1: " << segments[i].f.f << " " << segments[i].f.s << "\n";
            // cout << "p2: " << segments[i].s.f << " " << segments[i].s.s << "\n";
            // cout << "i: " << i << ", ans: " << ans << "\n";
        }
        cout << ans << "\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/