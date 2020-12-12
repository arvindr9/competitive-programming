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
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i =1 ;i <= n; i++) {
            cin >> a[i];
        }
        int first_good = n + 1;
        for (int i = n; i >= 1; i--) {
            if (a[i] == i) {
                first_good = i;
            } else {
                break;
            }
        }
        if (first_good == 1) {
            cout << 1 << "\n";
            for (int i = 1; i <= m; i++) {
                int elt;
                long double p;
                cin >> elt >> p;
            }
            continue;
        }
        int last_bad = first_good - 1;
        // cout << "last_bad: " << last_bad << "\n";
        // find probability of at least one >= last_bad being chosen (i.e. 1 - prob that all are less than last_bad)
        long double bad_prob = 1;
        for (int i = 1; i <= m; i++) {
            int elt;
            long double p;
            cin >> elt >> p;
            if (elt >= last_bad) { // not okay to sort this
                bad_prob *= ((long double)1 - p);
            }
        }
        long double ans = (long double)1 - bad_prob;
        cout << fixed << setprecision(7) <<  ans << "\n";


    }
} 