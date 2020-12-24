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
const int maxn = 105;
int a[maxn][maxn];

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int mn = inf;
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            mn = min(mn, a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1;i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += a[i][j] - mn;
        }
    }
    cout << ans << "\n";
} 