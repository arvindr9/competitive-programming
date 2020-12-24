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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    int g = 0;
    for (int i = 1; i < n; i++) {
        g = __gcd(g, abs(a[i] - a[i + 1]));
    }
    for (int i = 1; i <= m; i++) {
        int ans = __gcd(g, a[1] + b[i]);
        cout << ans << " ";
    }
    cout << "\n";
} 