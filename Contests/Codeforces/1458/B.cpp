// CF 1458 B

#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define pb push_back
#define eb emplace_back
#define f first
#define s second
const int inf = 1e18;

typedef long double T;

const int maxn = 105;
const int maxa = 1e4 + 5;
int dp[maxn][maxa]; // dp[num glasses][max capacity]

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("B.in", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < maxa; j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        int curcap = a[i];
        int curqty = b[i];
        for (int num_glasses = i; num_glasses > 0; num_glasses--) {
            for (int cap = maxa; cap > 0; cap--) {
                if (cap - a[i] >= 0) {
                    if (~dp[num_glasses - 1][cap - a[i]]) {
                        // cout << "num_glasses - 1: " << num_glasses - 1 << ", cap - a[i]: " << cap - a[i] << "\n";
                        // cout << "a[i]: " << a[i] << "\n";
                        // cout << "i: " << i << ", num_glasses: " << num_glasses << ", cap: " << cap << "\n";
                        dp[num_glasses][cap] = max(dp[num_glasses][cap], dp[num_glasses - 1][cap - a[i]] + b[i]);
                        // cout << "dp: " << dp[num_glasses][cap] << "\n";
                    }
                }
            }
        }
        // cout << "\n";
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= 20)
    // }

    int B = 0;
    for (int i = 1; i <= n; i++) B += b[i];

    for (int i = 1; i <= n; i++) {
        T ans = 0;
        for (int cap = 1; cap < maxa; cap++) {
            if (~dp[i][cap]) {
                T cand_ans = min((T)cap, (T)dp[i][cap] + (T)(B - dp[i][cap]) / (T)2);
                ans = max(ans, cand_ans);
            }
        }
        cout << fixed << setprecision(10) << ans << " ";
    }
    cout << "\n";
}