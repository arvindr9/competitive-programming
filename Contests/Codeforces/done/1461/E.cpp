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

int k, l, r, t, x, y;

bool inrange(int cur_mod, int l, int r) {
    // l and r difference at most x i think
    int m1 = l % x;
    int m2 = r % x;
    return cur_mod >= m1 or cur_mod <= m2;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> l >> r >> t >> x >> y;
    if (y <= x) {
        int ans = 0;
        // go down by x until fillable
        int cur_level = k;
        int req_to_fill = r - y;
        if (cur_level > req_to_fill) {
            // go down by ceil((k - req_to_fill) / x)
            int num_days = ((k - req_to_fill) + (x - 1)) / x;
            cur_level = k;
            // cout << "num_days: " << num_days << "\n";
            // cout << "subtreact result: " << k - num_days * x << "\n";
            // cout << "l: " << l << "\n";
            if (k - num_days * x >= l) {
                ans += num_days;
                cur_level = k - num_days * x;
            } else {
                ans += num_days - 1;
                cur_level = k - (num_days - 1) * x;
            }
        }
        // cout << "ans: " << ans << "\n";
        // cout << "cur_level: " << cur_level << "\n";
        if (cur_level > req_to_fill) { // i.e. couldn't go down
            if (ans >= t) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
                return 0;
            }
        }

        if (x == y) {
            cout << "Yes\n";
            return 0;
        }



        // remaining number of days: floor((cur_level - l) / (x - y))
        ans += (cur_level - l) / (x - y);
        // cout << "ans: " << ans << "\n";
        if (ans >= t) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return 0;
    }
    // y > x;
    if (r - y + 1 > l + x - 1) {
        cout << "Yes\n";
        return 0;
    }

    // i guess y is huge now lol (2y > r - l?)
    // not sure when to refill tbh
    // check all (k + ay) mod x, check if in range [l, req_to_fill]
    int req_to_fill = r - y;
    int ans = 0;
    int cur_level = k;
    bool forever = true;
    for (int i = 0; i < x; i++) {
        int cur_mod = cur_level % x;
        if (inrange(cur_mod, l, req_to_fill)) {
            // move cur_level to be near l, i.e. cur_level -= x * floor((cur_level - l) / x)
            ans += (cur_level - l) / x;
            cur_level -= x * ((cur_level - l) / x);
            // cout << "cur_level: " << cur_level << "\n";
        } else {
            forever = false;
            break;
        }
        // bring y up
        cur_level += y;
        // cout << "i: " << i << ", cur_level: " << cur_level << "\n";
        if (cur_level > r) {
            forever = false;
            break;
        }
    }
    // cout << "forever: " << forever << "\n";
    if (forever) {
        cout << "Yes\n";
        return 0;
    }
    // cout << "ans: " << ans << "\n";
    if (ans >= t) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
} 