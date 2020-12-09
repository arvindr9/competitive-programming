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
        int n, m;
        cin >> n >> m;
        vector<int> freq(105);
        int ans = 0;

        for (int i =1  ; i <= n; i++) {
            int a; cin >> a;
            freq[a]++;
        }

        for (int i = 1; i <= m; i++) {
            int a; cin >> a;
            freq[a]++;
            if (freq[a] == 2) ans++;
        }
        cout << ans << "\n";
    }
} 