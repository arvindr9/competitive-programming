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
        vector<int> a(n + 1);
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        int ans = inf;
        for (int i = 1; i <= n; i++) {
            int total_ops = 0;
            bool possible = true;
            int target = pre[i];
            for (int l = 1, r = 1; r <= n; ) {
                while (r <= n and pre[r] - pre[l - 1] < target) {
                    r++;
                }
                if (r > n or pre[r] - pre[l - 1] > target) {
                    possible = false;
                    break;
                }
                if (pre[r] - pre[l - 1] == target) {
                    total_ops += (r - l);
                    r++, l = r;
                }
            }
            if (!possible) continue;
            ans = min(ans, total_ops);
        }
        cout << ans << "\n";
    }
} 