#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 1;

int n, m, k;
const int maxn = 1e5 + 5;
const int maxc = 30;
int adj[maxc][maxc];
int a[maxn];
int pre_cost[maxn][maxc];
int dp1[maxn][maxc]; // last one incomplete
int dp2[maxn][maxc]; // last one complete
int dp0[maxn]; // last one complete, can be any arbitrary one

int get_cost(int l, int r, int c) {
    int res = pre_cost[r][c] - pre_cost[l - 1][c];
    return res;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    cin >> n >> m >> k;
    string st;
    cin >> st;
    for (int i = 1; i <= n; i++) {
        a[i] = (st[i - 1] - 'a') + 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> adj[i][j];
        }
    }
    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        char c = a[i];
        for (int j = 1; j <= m; j++) {
            pre_cost[i][j] = pre_cost[i - 1][j] + adj[c][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        dp0[i] = inf;
        for (int j = 1; j <= m; j++) {
            dp1[i][j] = inf;
            dp2[i][j] = inf;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp2[i][j] = min(dp2[i][j], dp2[i - 1][j] + get_cost(i, i, j));
        }
        if (i >= k) {
            for (int j = 1; j <= m; j++) {
                dp1[i][j] = min(dp1[i][j], dp1[i - 1][j] + get_cost(i, i, j));
                dp1[i][j] = min(dp1[i][j], dp2[i - k][j] + get_cost(i - k + 1, i, j));
                dp1[i][j] = min(dp1[i][j], dp0[i - k] + get_cost(i - k + 1, i, j));
            }
            for (int j = 1; j <= m; j++) {
                dp2[i][j] = min(dp2[i][j], dp1[i][j]);
            }
        }
        for (int j = 1; j <= m; j++) {
            dp0[i] = min(dp0[i], dp1[i][j]);
        }
    }

    int ans = dp0[n];
    cout << ans << "\n";


}