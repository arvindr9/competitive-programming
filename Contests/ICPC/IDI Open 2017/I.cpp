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

const int maxn = 205;
int r[maxn];
int r2[maxn];

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    sort(r + 1, r + n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> r2[i];
    }
    for (int i = m + 1; i <= m + k; i++) {
        int l;
        cin >> l;
        long double r = (long double)(l) / (long double)sqrt(2);
        r2[i] = (int)r;
    }
    sort(r2 + 1, r2 + m + k + 1);
    // cout << "plots:\n";
    // for (int i = 1; i <= n; i++) {
    //     cout << r[i] << " ";
    // }
    // cout << "\n";
    // cout << "houses:\n";
    // for (int i = 1; i <= m + k; i++) {
    //     cout << r2[i] << " ";
    // }
    // cout << "\n";
    int ans = 0;
    for (int i = 1, j = 1; i <= n and j <= m + k; ) {
        if (r2[j] < r[i]) {
            // new house
            ans++;
            j++;
            i++;
        } else {
            // plot is too small
            i++;
        }
    }
    cout << ans << "\n";

} 