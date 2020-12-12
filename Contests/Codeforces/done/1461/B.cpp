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
#define inf 1e18

int t;

int n, m;

int compute(vector<vector<int>> &pres, int i, int j, int k) {
    int curi = i + k - 1;
    int minj = j - k + 1;
    int maxj = j + k - 1;
    if (curi > n or minj < 1 or maxj > m) return 0;
    int ans = pres[curi][maxj] - pres[curi][minj - 1];
    // cout << "i : " << i << ", j: " << j << ", k: " << k << ", ans: " << ans << "\n";
    return ans;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<char>> grid(n + 1, vector<char>(m + 1));
        vector<vector<int>> pres(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            string st;
            cin >> st;
            for (int j = 1; j <= m; j++) {
                grid[i][j] = st[j - 1];
                pres[i][j] = pres[i][j - 1] + (grid[i][j] == '*');
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= m; k++) {
                    if (compute(pres, i, j, k) == 2 * k - 1) ans++;
                    else break;
                }
            }
        }
        cout << ans << "\n";
        
    }
} 