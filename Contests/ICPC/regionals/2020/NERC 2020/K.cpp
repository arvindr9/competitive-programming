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

pi get_next(pi loc, char c, pi obstacle) {
    pi next_loc = loc;
    if (c == 'U') next_loc.s++;
    else if (c == 'D') next_loc.s--;
    else if (c == 'L') next_loc.f--;
    else if (c == 'R') next_loc.f++;
    if (next_loc == obstacle) return loc;
    return next_loc;
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        string st;
        cin >> st;
        int n = st.size();
        vector<pi> locs = {mp(0, 0)};
        for (int i = 0; i < n; i++) {
            pi cur_loc = locs.back();
            if (st[i] == 'U') cur_loc.s++;
            else if (st[i] == 'D') cur_loc.s--;
            else if (st[i] == 'L') cur_loc.f--;
            else if (st[i] == 'R') cur_loc.f++;
            locs.pb(cur_loc);
        }

        function<bool(pi)> valid = [&](pi obstacle) {
            if (obstacle == make_pair(0LL, 0LL)) return false;
            // cout << "obstacle: " << obstacle.f << " " << obstacle.s << "\n";
            pi cur_loc = {0, 0};
            for (int i = 0; i < n; i++) {
                cur_loc = get_next(cur_loc, st[i], obstacle);
            }
            if (cur_loc == mp(0LL, 0LL)) return true;
            return false;
        };

        bool done = false;
        for (pi loc: locs) {
            if (valid(loc)) {
                cout << loc.f << " " << loc.s << "\n";
                done = true;
                break;
            }
        }
        // cout << "done: " << done << "\n";
        if (!done) {
            cout << "0 0\n";
        }

    }
} 