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
int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> exists(2 * n + 1);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            exists[a]++;
        }
        int pre = 0, mn = 0, mx = 0;
        for (int i = 1; i <= 2 * n; i++) {
            if (exists[i]) pre++;
            else pre--;
            mn = min(mn, pre);
            mx = max(mx, pre);
        }
        int rng = mx - mn;
        int ans = abs(n - rng) + 1;
        cout << ans << "\n";
    }
} 