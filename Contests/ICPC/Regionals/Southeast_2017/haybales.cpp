#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2050;
const int large = 987654321;

map<int, deque<ll>> dpwindowi;
map<int, deque<ll>> dpwindowj;
ll dp[maxn][maxn];
bool accessible[maxn][maxn];
int n, k;

int main() {
    //freopen("haybales.in", "r", stdin);
    //freopen("haybales.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = large;
        }
    }
    dp[n][n] = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            accessible[i][j] = ( s[j - 1] == '.' ? true : false);
        }
    }
    for (int j = n; j >= 1; j--) {
        for (int i = n; i >= 1; i--) {
            if (j + k + 1 <= n && dpwindowi[i].size() != 0 && dpwindowi[i].front() == dp[i][j + k + 1]) {
                dpwindowi[i].pop_front();
            }
            if (i + k + 1 <= n && dpwindowj[j].size() != 0 && dpwindowj[j].front() == dp[i + k + 1][j]) {
                dpwindowj[j].pop_front();
            }
            if (!accessible[i][j]) continue;
            if (dpwindowi[i].size() != 0) dp[i][j] = min(dp[i][j], 1 + dpwindowi[i].front());
            if (dpwindowj[j].size() != 0) dp[i][j] = min(dp[i][j], 1 + dpwindowj[j].front());
            while (dpwindowi[i].size() != 0 && dp[i][j] < dpwindowi[i].back()) {
                dpwindowi[i].pop_back();
            }
            dpwindowi[i].push_back(dp[i][j]);
            while (dpwindowj[j].size() != 0 && dp[i][j] < dpwindowj[j].back()) {
                dpwindowj[j].pop_back();
            }
            dpwinodwj[j].push_back(dp[i][j]);
        }
    }
    if (dp[1][1] == large) dp[1][1] = -1;
    cout << dp[1][1] << "\n";
}
