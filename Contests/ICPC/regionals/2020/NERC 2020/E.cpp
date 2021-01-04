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

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        vector<int> v(4);
        for (int i = 0; i < 4; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int ans = v[0] * v[2];
        cout << ans << "\n";
    }
} 