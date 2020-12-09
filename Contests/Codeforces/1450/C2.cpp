#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
typedef int int2;
#define pi pair<int, int>
#define int long long
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

int reduce(int a) {
    return (a %= 3) < 0? a + 3: a;
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        vector<pi> offsets = {mp(0, 1), mp(1, 2), mp(2, 0), mp(1, 2), mp(2, 1), mp(0, 2)};
        pi best_offset;
        int min_ops = 1e6 + 5;
        for (pi offset: offsets) {
            int total_ops = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (reduce(i + j + offset.f) == 0) {
                        if (grid[i][j] == 'X') {
                            total_ops++;
                        }
                    } else if (reduce(i + j + offset.s) == 0) {
                        if (grid[i][j] == 'O') {
                            total_ops++;
                        }
                    }
                }
            }
            if (total_ops < min_ops) {
                min_ops = total_ops;
                best_offset = offset;
            }
        }
        // cout << "min_ops: " << min_ops << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (reduce(i + j + best_offset.f) == 0) {
                    if (grid[i][j] == 'X') {
                        grid[i][j] = 'O';
                    }
                } else if (reduce(i + j + best_offset.s) == 0) {
                    if (grid[i][j] == 'O') {
                        grid[i][j] = 'X';
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/