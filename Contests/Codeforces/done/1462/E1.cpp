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

const int mod = 1e9 + 7;


inline int reduce(int a) {
    return (a %= mod) < 0 ? a + mod : a;
}

inline int add(int a, int b) {
    return reduce(a + b);
}

inline int prod(int a, int b) {
    return reduce(a * b);
}

inline int modpow(int a, int pw) {
    if (pw == 0) return 1;
    if (pw % 2 == 0) {
        int res = modpow(a, pw / 2);
        return prod(res, res);
    }
    return prod(a, modpow(a, pw - 1));
}

inline int inv(int a) {
    return modpow(a, mod - 2);
}
const int maxp = 2e5 + 5;
int fact[maxp];

inline int binom(int a, int b) {
    return a * (a - 1) / 2;
}

void process_fact() {
    fact[0] = 1;
    for (int i = 1; i < maxp; i++) {
        fact[i] = prod(fact[i - 1], i);
    }
}

int t;

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    process_fact();
    while (t--) {
        int n, m, k;
        cin >> n;
        m = 3;
        k = 2;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin>> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int l = 0, r = 0; l < n;) {
            // find earliest r such that a[r] - a[l] > k
            while (r < n and a[r] - a[l] <= k) {
                r++;
            }
            // num ways to pick from [l + 1...n-1] - num ways to pick from [l + 1...r - 1]
            // check that n - 1 - l >= m
            // cout << "l: " << l << ", r: " << r << "\n";
            int numways = 0;
            // if (n - l >= m) {
            //     cout << "n - l: " << n - l << "\n";
            //     // cout << "n "
            //     cout << "binom: " << binom(n - l - 1, m - 1) << "\n";
            //     numways = add(numways, binom(n - l - 1, m - 1));
            // }
            if (r - l >= m) {
                // cout << "r - l + 1: " << r - l << "\n";
                // cout << "binom: " << binom(r - l - 1, m - 1) << "\n";
                numways += binom(r - l - 1, m - 1);
            }
            ans += numways;
            l++, r = max(r, l);
        }
        cout << ans << "\n";
    } 
} 