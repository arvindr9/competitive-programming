#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;

typedef int int2;
#define int long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define all(x) x.begin(), x.end()

mt19937_64 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

const int maxn = 1e6 + 5;
int t;
int n, k;


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pi> pts(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            pts[i] = mp(x, y);
        }

        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }

        bool possible = false;
        for (int i = 0; i < n; i++) {
            //ith pt as candidate
            bool all_within = true;
            for (int j = 0; j < n; j++) {
                int d = abs(pts[i].f - pts[j].f) + abs(pts[i].s - pts[j].s);
                if (d > k) all_within = false;
            }
            possible = possible or all_within;
        }
        if (possible) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
        
        
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/