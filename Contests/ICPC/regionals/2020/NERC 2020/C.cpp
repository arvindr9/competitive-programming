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

// const int maxn = 5e5 + 5;
// queue<int> customers[maxn];
// pi t[2 * maxn]; // mth leaf is of the form (-t, m)
// int n = maxn;

// void pull(int v) {
//     t[v] = min(t[2 * v], t[2 * v + 1]);
// }

// void update(int v, int tl, int tr, int pos, pi val) {
//     if (tl == tr) {
//         t[v] = val;
//     }
//     int tm = (tl + tr) / 2;
//     if (pos <= tm) {
//         update(2 * v, tl, tm, pos, val);
//     } else {
//         update(2 * v, tm + 1, tr, pos, val);
//     }
//     pull(v);
// }

// pi query(int v, int tl, int tr, int l, int r) {
//     if (r > l) return {inf, inf};
//     if (l == tl and r == tr) return t[v];
//     int tm = (tl + tr) / 2;
//     return min(query(2 * v, tl, tm, l, min(tm, r)), query(2 * v + 1, tm + 1, tr, max(tm + 1, l), tr));
// }

// void update(int pos, pi val) {
//     update(1, 1, n, pos, val);
// }

// pi query(int l, int r) {
//     return query(1, 1, n, l, r);
// }

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    set<pi> time_better; // {time, m}
    set<pi> m_better; // {-m, time}
    int tt = 0;
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            tt++;
            int m;
            cin >> m;
            // customers[m].push(i);
            time_better.emplace(tt, m);
            m_better.emplace(-m, tt);
        }
        else if (type == 2) {
            // time better
            pi opt = *(time_better.begin());
            auto &[t, m] = opt;
            // cout << "type2:\n";
            // cout << "opt: " << opt.f << " " << opt.s << "\n";
            time_better.erase(opt);
            m_better.erase(mp(-m, t));
            cout << t << "\n";
        } else if (type == 3) {
            // m better
            // cout << "type3:\n";
            pi opt = *(m_better.begin());
            // cout << "opt: " << opt.f << " " << opt.s << "\n";
            auto &[m, t] = opt;
            m_better.erase(opt);
            time_better.erase(mp(t, -m));
            cout << t << "\n";
        }
    }
} 