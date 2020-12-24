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

bool invalidd(int n) {
    while (n > 0) {
        if (n % 10 == 7) return true;
        n /= 10;
    }
    return false;
}

bool invalido(int n) {
    while (n > 0) {
        // cout << "n: " << n << ", n&7: " << (n&7) << "\n";
        if ((n & 7) == 7) return true;
        n /= 8;
    }
    return false;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = n;
    for (int i = 1; i <= n; i++) {
        if (invalidd(i)) {
            // cout << "dd, i: " << i << "\n";
            ans--;
        } else if (invalido(i)) {
            // cout << "do, i: " << i << "\n";
            ans--;
        }
    }
    cout << ans << "\n";
} 