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

const int maxn = 105;

int dp[2][maxn][maxn];

int solve(int black, int r, int c) {
    if (~dp[black][r][c]) return dp[black][r][c];
    if (r == 0 or c == 0) return dp[black][r][c] = 0;
    int res = -inf;
    // cout << "res: " << res << "\n";
    int black2 = (black + r - 1) % 2;
    int b_minus_w = 0;
    if (r % 2 == 1) {
        if (black) {
            b_minus_w = 1;
        } else {
            b_minus_w = -1;
        }
    }
    for (int k = 1; k <= c; k++) {
        black2 ^= 1;
        // cout << "c - k: " << c - k << ", r: " << r << "\n";
        // cout << "b_minus_w: " << b_minus_w << "\n";
        int candidate_dp = b_minus_w * (int)(k % 2 == 1) - solve(black2, c - k, r);
        // cout << "candidate_dp: " << candidate_dp << "\n";
        res = max(res, candidate_dp);
    }
    return dp[black][r][c] = res;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < maxn; j++) {
            for (int k = 0; k < maxn; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    int n, m;
    cin >> n >> m;
    // int a = solve(0, 1, 1);
    // cout << "a: " << a << "\n";
    int ans = solve(1, n, m);
    cout << ans << '\n';
} 