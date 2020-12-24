#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
const int inf = 1e18;

int t;

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int numA = 0;
        int numP = 0;
        vector<vector<char>> grid(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= n; i++) {
            string st;
            cin >> st;
            for (int j = 1; j <= m; j++) {
                grid[i][j] = st[j - 1];
            }
        }
        function<int(int, int, int, int)> countP = [&](int imin, int imax, int jmin, int jmax) {
            int ans = 0;
            for (int i = imin; i <= imax; i++) {
                for (int j = jmin; j <= jmax; j++) {
                    if (grid[i][j] == 'P') ans++;
                }
            }
            return ans;
        };
        if (countP(1, n, 1, m) == n * m) {
            cout << "MORTAL\n";
            continue;
        }
        if (countP(1, n, 1, m) == 0) {
            cout << 0 << "\n";
            continue;
        }
        // check to see if it can be done in 1
        if (countP(1, n, 1, 1) == 0 or countP(1, n, m, m) == 0 or countP(1, 1, 1, m) == 0 or countP(n, n, 1, m) == 0) {
            cout << 1 << "\n";
            continue;
        }
        // check if can be done in 2
        if (grid[1][1] == 'A' or grid[1][m] == 'A' or grid[n][1] == 'A' or grid[n][m] == 'A') {
            cout << 2 << "\n";
            continue;
        }
        // columns
        bool done = false;
        for (int i = 2; i < m; i++) {
            if (countP(1, n, i, i) == 0) {
                done = true;
                break;
            }
        }
        // rows
        for (int i = 2; i < n; i++) {
            if (countP(i, i, 1, m) == 0) {
                done = true;
                break;
            }
        }
        if (done) {
            cout << 2 << "\n";
            continue;
        }

        // check see if it can be in 3
        if (countP(1, 1, 1, m) < m or countP(n, n, 1, m) < m or countP(1, n, 1, 1) < n or countP(1, n, m, m) < n) {
            cout << 3 << "\n";
            continue;
        }
        cout << 4 << "\n";
    }
} 