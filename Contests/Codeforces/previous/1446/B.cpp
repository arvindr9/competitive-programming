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

const int maxn = 5005;

int dp[maxn][maxn];
int prev1[maxn][26], prev2[maxn][26];

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < 26; j++) {
            prev1[i][j] = prev2[i][j] = -1;
        }
    }
    int n, m;
    cin >> n >> m;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    // cout << "s2[0]: " << s2[0] << "\n";

    for (int i = 0; i < n; i++) {
        int val1 = s1[i] - 'a';
        for (int j = i + 1; j < n; j++) {
            prev1[j][val1] = i;
        }
    }
    for (int i = 0; i < m; i++) {
        int val1 = s2[i] - 'a';
        for (int j = i + 1; j < m; j++) {
            prev2[j][val1] = i;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s1[i] == s2[j]) {
                // cout << "s1: " << s1 << ", s2: " << s2 << "\n";
                // cout << "i: " << i << ", j: " << j << ", s1: " << s1[i] << ", s2: " << s2[j] << "\n";
                int val = s1[i] - 'a';
                dp[i][j] = 2; //just include that char in the LCS
                for (int prv = 0; prv < 26; prv++) {
                    int i1 = prev1[i][prv];
                    int i2 = prev2[j][prv];
                    if ((~i1) and (~i2)) {
                        int new_dp = dp[i1][i2] + 4 - (i - i1) - (j - i2);
                        if (new_dp > dp[i][j]) {
                            // cout << "new dp:  " << new_dp << ", i1: " << i1 << ", i2: " << i2 << "\n";
                        }
                        dp[i][j] = max(dp[i][j], new_dp);
                    }
                }
                // cout << "i: " << i << ", j: " << j << ", dp: " << dp[i][j] << "\n";
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
} 