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
    cin >> t;
    while (t--) {
        int n, l;
        cin >> n >> l;
        vector<ld> a(n + 2);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[n + 1] = l;
        vector<pair<ld, pi> > checkpts; // {time, {car id, flag no}}
        ld total_time = 0;
        checkpts.push_back({0, {0, 0}});
        ld speed = 1;
        for (int i = 1; i <= n + 1; i++) {
            total_time += (a[i] - a[i - 1]) / speed;
            // cout << "totaltime0: " << total_time << "\n";
            checkpts.push_back({total_time, {0, i}});
            speed++;
        }

        checkpts.push_back({0, {1, n + 1}});
        speed = 1;
        total_time = 0;
        for (int i = n; i >= 1; i--) {
            total_time += (a[i + 1] - a[i]) / speed;
            // cout << "totaltime1: " << total_time << "\n";
            checkpts.push_back({total_time, {1, i}});
            speed++;
        }

        ld ans = 0;
        // cout << "ans: " << ans << "\n";
        sort(all(checkpts));
        int num_check = checkpts.size();
        pair<ld, pi> p0 = {-2, {0, 0}};
        pair<ld, pi> p1 = {-2, {0, 0}};
        for (int i = 0; i < num_check; i++) {
            pair<ld, pi> cur_check = checkpts[i];
            if (cur_check.s.f == 0) p0 = cur_check;
            else p1 = cur_check;
            if (p0.f < -1 or p1.f < -1) continue;
            int f0 = p0.s.s;
            int f1 = p1.s.s;
            if (f1 - f0 == 1) {
                ld t0 = p0.f;
                ld t1 = p1.f;
                // cout << "f0: " << f0 << ", f1: " << f1 << "\n";
                // cout << "t0: " << t0 << ", t1:  " << t1 << "\n";
                ld s0 = f0 + 1;
                ld s1 = (n + 1) - f1 + 1;
                ld d = a[f1] - a[f0];
                if (t0 < t1) {
                    ld k = t1 - t0;
                    ans = t0 + (d + k * s1) / (s0 + s1);
                } else {
                    ld k = t0 - t1;
                    ans = t1 + (d + k * s0) / (s0 + s1);
                }
                break;
            }
        }
        cout << setprecision(8) << fixed << ans << "\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/