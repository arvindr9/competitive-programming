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

const int maxn = 2e5 + 5;
int n, m;
vector<pi> illegals;
int rx[maxn], ry[maxn], lx[maxn], ly[maxn];

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<pi> illeg1;
    for (int i = 1; i <= n; i++) {
        cin >> rx[i] >> ry[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> lx[i] >> ly[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (rx[i] <= lx[j] and ry[i] <= ly[j]) {
                illeg1.push_back(mp(lx[j] - rx[i], ly[j] - ry[i]));
            }
        }
    }
    sort(all(illeg1));
    int num_illeg = illeg1.size();
    // cout << "num_illeg: " << num_illeg << "\n";
    for (int i = 0; i < num_illeg; i++) {
        pi curp = illeg1[i];
        if (illegals.empty()) {
            illegals.pb(curp);
        } else {
            while (!illegals.empty() and illegals.back().s <= curp.s) {
                illegals.pop_back();
            }
            if (illegals.empty()) {
                illegals.pb(curp);
            } else {
                pi lastp = illegals.back();
                if (lastp.f < curp.first) {
                    illegals.pb(curp);
                }
            }
        }
    }
    int ans = 1e9;
    int last_x = 0;
    for (pi p: illegals) {
        // cout << "x: " << p.f << ", y: " << p.s << "\n";
        int y = p.s;
        ans = min(ans, last_x + y + 1);
        last_x = p.f + 1;
        // cout << "last_x: " << last_x << "\n";
    }
    ans = min(ans, last_x);
    cout << ans << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/