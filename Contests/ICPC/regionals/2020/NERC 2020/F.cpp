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

pi reduce(pi p) {
    int dx = p.f;
    int dy = p.s;
    if (dx == 0) dy /= abs(dy);
    else if (dy == 0) dx /= abs(dx);
    else {
        int g = abs(__gcd(dx, dy));
        dx /= g, dy /= g;
    }
    return mp(dx, dy);
}
pi negatee(pi p) {
    return mp(-p.f, -p.s);
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n), y(n), u(n), v(n);
        vector<pi> dirs(n);
        map<pi, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> u[i] >> v[i];
            dirs[i] = mp(u[i] - x[i], v[i] - y[i]);
            dirs[i] = reduce(dirs[i]);
            freq[dirs[i]]++;
        }
        int ans = 0;
        for (auto &e: freq) {
            pi dxdy = e.f;
            int f = e.s;
            pi negative = negatee(dxdy);
            if (freq.count(negative)) {
                ans += f * freq[negative];
            }
        }
        ans /= 2;
        cout << ans << "\n";
    }
} 