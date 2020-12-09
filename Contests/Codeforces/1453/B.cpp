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

int t;

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> ops(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int target = a[0];
        int offset = 0;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ops[i] = target - (a[i] + offset);
            offset += ops[i];
            ans += abs(ops[i]);
            // cout << "op: " << ops[i] << "\n";
        }
        int ans0 = ans;
        // cout << "ans: " << ans << "\n";
        for (int i = 0; i < n - 1; i++) {
            // change ith element
            int target;
            if (i == 0) target = a[1];
            else target = a[i - 1];
            // change s.t. ith number of ops is 0
            int new_ans = ans0 - abs(ops[i]) - abs(ops[i + 1]);
            new_ans += abs(a[i + 1] - target);
            // cout << "i: " << i << ", new_ans: " << new_ans << "\n";
            ans = min(ans, new_ans);
            // cout << "ans: " << ans << "\n";
        }
        ans = min(ans, ans0 - abs(ops[n - 1]));
        // cout << "ans: " << ans << "\n";
        cout << ans << "\n";
    }
} 