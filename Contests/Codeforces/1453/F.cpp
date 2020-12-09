#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second

#define INF 1e18


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = INF;
            }
        }
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = i - 1; j >= 1; j--) {
                if (j + a[j] >= i) {
                    dp[i][j + a[j]] = min(dp[i][j + a[j]], dp[j][i - 1] + cnt);
                    cnt++;
                }
            }
            for (int j = i + 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
        }
        cout << dp[n][n] << "\n";
    }
}