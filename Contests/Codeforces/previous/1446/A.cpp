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

int t, n, W;

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> W;
        vector<pi> a(n);
        for (int i = 0; i < n; i++) {
            int elt;
            cin >> elt;
            a[i] = mp(elt, i + 1);
        }
        sort(a.begin(), a.end());
        int half = (W + 1) / 2;

        // check if there exists an valid single element in the range
        bool done = false;
        for (int i = 0; i < n; i++) {
            pi elt = a[i];
            int val = elt.f;
            if (val >= half and val <= W) {
                cout << 1 << "\n";
                cout << elt.s << "\n";
                done = true;
                break;
            }
        }
        if (done) {
            continue;
        }
        
        // check sum of elements
        vector<int> ans;
        int total_sm = 0;
        for (int i = 1; i <= n; i++) {
            total_sm += a[i - 1].f;
            ans.pb(a[i - 1].s);
            if (total_sm >= half and total_sm <= W) break;
        }

        if (total_sm < half or total_sm > W) {
            cout << -1 << "\n";
            continue;
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (int i: ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
} 