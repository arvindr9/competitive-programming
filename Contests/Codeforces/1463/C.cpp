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

int sign(int x) {
    if (x > 0) return 1;
    else if (x < 0) return -1;
    return 0;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<array<int, 4>> actuals; //t, start, end, dur
        vector<int> ts(n + 1);
        ts[n] = inf;
        vector<int> xs(n);
        for (int i = 0; i < n; i++) {
            cin >> ts[i] >> xs[i];
        }
        // int num_bad = 0;
        int curt = 0;
        int curx = 0;
        for (int i = 0; i < n; i++) {
            if (ts[i] < curt) {
                continue;
            }
            // cout << "i: " << i << ", ts: " << ts[i] << ", curt: " << curt << "\n";
            if (ts[i] > curt) actuals.pb({curt, curx, curx, ts[i] - curt});
            int delta = xs[i] - curx;
            actuals.push_back({ts[i], curx, xs[i], abs(xs[i] - curx)});
            curt = ts[i] + abs(delta);
            curx = xs[i];
        }

        int num_good = 0;
        for (int i = 0; i < n; i++) {
            // check if xs[i] is in [ts[i], ts[i + 1]] 
            auto it = lower_bound(actuals.begin(), actuals.end(), (array<int, 4>){ts[i], -inf, -inf, -inf});
            array<int, 4> arr = *it;
            if (it != actuals.begin()) it--;
            int tt, start, nd, dur;
            // cout << "i: " << i << "\n";
            while (it != actuals.end()) {
                if ((*it)[0] > ts[i]) break;
                arr = *it;
                tt = arr[0], start = arr[1], nd = arr[2], dur = arr[3];
                // cout << "tt: " << tt << ", start: " << start << ", nd: " << nd << ", dur: " << dur << "\n";
                // tt + dur will be >= t[i]
                int dir = sign(nd - start);
                int fst = start + (ts[i] - tt) * dir;
                int sec = start + min(dur, ts[i + 1] - tt) * dir;
                int tmax = tt + dur;
                if (xs[i] >= min(fst, sec) and xs[i] <= max(fst, sec)) {
                    num_good++;
                    break;
                } else {
                    if (tmax <= ts[i]) {
                        it++;
                    } else {
                        break;
                    }
                }
            }
        }
        cout << num_good << "\n";
    }
} 