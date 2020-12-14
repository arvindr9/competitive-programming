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

map<string, long double> best;

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    best["pink"] = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s1, s2;
        long double r;
        cin >> s1 >> s2 >> r;
        if (best.count(s2)) {
            if (best.count(s1)) {
                best[s1] = max(best[s1], best[s2] + log(r));
            } else {
                best[s1] = best[s2] + log(r);
            }
        }
    }
    if (!best.count("blue")) {
        cout << 0 << "\n";
        return 0;
    }
    long double bb = best["blue"];
    long double thresh = log(10);
    if (bb >= thresh) {
        cout << 10 << "\n";
    }
    else {
        cout << fixed << setprecision(7) << exp(bb) << "\n";
    }
} 