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
        int c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        int a1, a2, a3, a4, a5;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        c1 -= a1, c2 -= a2, c3 -= a3;
        if (min({c1, c2, c3}) < 0) {
            cout << "No\n";
            continue;
        }
        a4 = max(0LL, a4 - c1), a5 = max(0LL, a5 - c2);
        if (c3 >= a4 + a5) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
} 