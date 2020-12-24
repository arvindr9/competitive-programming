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
const int maxn = 2e5 + 5;
int a[maxn], suf[maxn];

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    suf[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += suf[i + 1] - (n - i) * a[i];
    }
    cout << ans << "\n";
} 