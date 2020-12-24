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

int reduce(int a, int mod) {
    return (a %= mod) < 0 ? a + mod : a;
}

// source: kactl
// finds x, y such that ax + by = gcd(a, b)

typedef long long ll;
ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n, s, k;
        cin >> n >> s >> k;
        s = n - s;
        int g = __gcd(k, n);

        if (s % g != 0) {
            cout << -1 << "\n";
            continue;
        }

        // goal: find smallest positive integer x such that kx = s mod n
        int x, y;
        // kx + ny = g
        euclid(k, n, x, y);
        // kx + ny = s
        x *= (s / g), y *= (s / g);
        // ans: x % (n / g)
        x = reduce(x, n / g);
        cout << x << "\n";
    }
} 