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
#define INF 1e18

int t;
const int maxn = 5e3 + 5;
int lastn[maxn];
int dp[maxn][maxn]; // dp[castles finished][troops remaining]
bool possible[maxn][maxn];
int sufmax[maxn]; // required number of troops to defeat [i...n]
vector<int> cs[maxn];
int a[maxn], b[maxn], c[maxn];
int n, m, k;

int solve(int done, int troops) {
    if (~dp[done][troops]) return dp[done][troops];
    // check if possible to defeat remaining
    if (troops < sufmax[done + 1]) {
        possible[done][troops] = false;
        return dp[done][troops] = -2;
    }
    if (done > n) {
        return dp[done][troops] = 0;
    }
    // send troops to earlier locations
    int ans = 0;
    // send 0 troops to earlier castles (this is always possible i think)
    int ans2 = solve(done + 1, troops + b[done + 1]);
    ans = max(ans, ans2);

    int num_troops = cs[done].size();
    int csum = 0;
    for (int i = 1; i <= min(troops, num_troops); i++) {
        csum += cs[done][i - 1];
        if (troops - i < sufmax[done + 1]) break;
        int ans2 = solve(done + 1, troops - i + b[done + 1]);
        // cout << "\ndone: " << done << ", troops: " << troops << ", num_troops: " << num_troops << "csum: " << csum << "\n";
        // cout << "ans2: " << ans2 << "\n";
        if (possible[done + 1][troops - i + b[done + 1]]) {
            // cout << "possible\n";
            ans = max(ans, csum + ans2);
        }
        // cout << "ans: " << ans << "\n";
    }
    // cout << "done: " << done << ", troops: " << troops << ", ans: " << ans << "\n";
    // cout << "possible: " << possible[done][troops] << "\n";
    return dp[done][troops] = ans;


}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j < maxn; j++) {
            dp[i][j] = -1;
            possible[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        lastn[i] = i;
    }
    sufmax[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        sufmax[i] = max(a[i], sufmax[i + 1] - b[i]);
    }
    for (int i = 1; i <= m; i++) {
        int u, v; // u > v
        cin >> u >> v;
        lastn[v] = max(lastn[v], u);
    }
    for (int i = 1; i <= n; i++) {
        cs[lastn[i]].pb(c[i]);
    }
    for (int i = 1; i <= n; i++) {
        sort(cs[i].begin(), cs[i].end());
        reverse(cs[i].begin(), cs[i].end());
    }
    int ans = solve(0, k);
    if (ans == -2) cout << -1 << "\n";
    else cout << ans << "\n";
} 