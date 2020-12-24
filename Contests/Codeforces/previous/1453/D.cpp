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
        int k;
        cin >> k;
        if (k % 2 == 1) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> lengths;
        int curexp = 1;
        int curpow = 2;
        while (curpow * 2 * 2 - 2 <= k) {
            curpow *= 2;
            curexp++;
        }
        lengths.pb(curexp);
        k -= 2 * curpow - 2;
        while (k > 0) {
            while (2 * curpow - 2 > k) {
                curpow /= 2;
                curexp--;
            }
            lengths.pb(curexp);
            k -= 2 * curpow - 2;
        }
        vector<int> ans;
        while (!lengths.empty()) {
            int curlength = lengths.back();
            lengths.pop_back();
            ans.pb(1);
            for (int i = 2; i <= curlength; i++) {
                ans.pb(0);
            }
        }
        cout << ans.size() << "\n";
        for (int i: ans) {
            cout << i << " ";
        }
        cout << "\n";
        
    }
} 