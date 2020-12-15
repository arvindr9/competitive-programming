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

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int cursum = 0;
        vector<int> ans;
        for (int i = 9; i >= 1; i--) {
            if (cursum + i <= x) {
                cursum += i;
                ans.pb(i);
            }
        }
        if (cursum == x) {
            reverse(ans.begin(), ans.end());
            for (int elt: ans) {
                cout << elt;
            }
            cout << "\n";
            continue;
        }
        cout << -1 << "\n";

    }
} 