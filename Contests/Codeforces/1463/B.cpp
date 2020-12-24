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
        int sm = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) sm += a[i];
        vector<int> res;
        for (int i = 1; i <= n; i++) {
            int pwr = 1;
            // find pwr s.t. abs(a[i] - pwr) <= a[i] / 2
            for (int j = 1; j <= 40; j++) {
                if (2LL * abs(a[i] - pwr) <= a[i]) {
                    res.pb(pwr);
                    break;
                }
                pwr <<= 1;
            }
        }
        for (int elt: res) {
            cout << elt << " ";
        }
        cout << "\n";
        // int mean1 = sm / n;
        // int mean2 = mean1 + 1;
        // int s1 = 0;
        // int s2 = 0;
        // for (int i = 1; i <= n; i++) s1 += abs(a[i] - mean1), s2 += abs(a[i] - mean2);
        // cout << "mean1: " << mean1 << ", mean2: " << mean2 << "\n";
        // cout << "sm: " << sm << "\n";
        // cout << "2 * s1: " << (2 * s1) << "\n";
        // if (2 * s1 <= sm) {
        //     for (int i = 1; i <= n; i++) {
        //         cout << mean1 << " ";
        //     }
        // } else {
        //     for (int i = 1; i <= n; i++) {
        //         cout << mean2 << " ";
        //     }
        // }
        // cout << "\n";
    }
} 