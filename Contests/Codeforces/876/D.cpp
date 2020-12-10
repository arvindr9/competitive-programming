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
#define INF 1e18

const int maxn = 3e5 + 5;
#define INF 1e18
int t[4 * maxn];

void pull(int v) {
    t[v] = t[2 * v] + t[2 * v + 1];
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) update(2 * v, tl, tm, pos, val);
        else update(2 * v + 1, tm + 1, tr, pos, val);
        pull(v);
    }
}

int query_sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl and r == tr) return t[v];
    int tm = (tl + tr) / 2;
    return query_sum(2 * v, tl, tm, l, min(tm, r)) + query_sum(2 * v + 1, tm + 1, tr, max(tm + 1, l), tr);
}
int n;

void update(int pos, int val) {
    update(1, 1, n, pos, val);
}

int query_sum(int l, int r) {
    return query_sum(1, 1, n, l, r);
}

void print(set<pi> gaps) {
    for (pi p: gaps) {
        cout << p.f << " " << p.s << ", ";
    }
    cout << "\n";
}

void cut(set<pi> &gaps, int idx) {
    //find the appropriate pair to cut
    auto it = gaps.upper_bound({idx, INF});
    it--;
    if (it->f == it->s) {
        gaps.erase(it);
    } else {
        if (idx == it->f) {
            // cout << "equality w/ first " << "\n";
            pi new_elt = {it->f + 1LL, it->s};
            gaps.erase(it);
            // cout << "new elt: " << new_elt.f << " " << new_elt.s << "\n";
            gaps.insert(new_elt);
        } else if (idx == it->s) {
            pi new_elt = {it->f, it->s - 1LL};
            gaps.erase(it);
            gaps.insert(new_elt);
        } else {
            pi p1 = {it->f, idx - 1};
            pi p2 = {idx + 1, it->s};
            gaps.erase(it);
            gaps.insert(p1);
            gaps.insert(p2);
        }
    }
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    set<pi> gaps;
    gaps.emplace(1, n);
    cout << 1 << " ";
    // print(gaps);

    for (int i = 1; i <= n; i++) {
        int idx;
        cin >> idx;
        cut(gaps, idx);
        if (gaps.empty()) {
            cout << 1 << " ";
            continue;
        }
        int last_gap = gaps.rbegin()->s;
        // cout << "last_gap: " << last_gap << "\n";
        // print(gaps);
        int ans = i - (n - last_gap - 1);
        cout << ans << " ";
    }
    cout << "\n";
    // for (int i = 1; i <= n; i++) {
    //     int idx;
    //     cin >> idx;
    //     int old_inv = query_sum(1, idx - 1);
    //     num_inv -= old_inv;
    //     update(idx, 1);
    //     int new_inv = (n - idx) - query_sum(idx + 1, n);
    //     num_inv += new_inv;
    //     cout << (num_inv + 1) << " ";
    //     cout << "\n";
    // }
} 