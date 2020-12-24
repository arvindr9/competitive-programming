// ABC 186 F

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

struct lazyseg_sum {
    int n;
    vector<int> t;
    vector<int> ladd;
    lazyseg_sum(int _n) {
        n = _n;
        t.resize(4 * n + 5);
        ladd.resize(4 * n + 5);
    }
    void pull(int v) {
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    void push(int v, int tl, int tr) {
        int tm = (tl + tr) / 2;
        t[2 * v] += (tm - tl + 1) * ladd[v], t[2 * v + 1] += (tr - tm + 1) * ladd[v];
        ladd[2 * v] += ladd[v], ladd[2 * v + 1] += ladd[v], ladd[v] = 0;
    }
    void update(int v, int tl, int tr, int l, int r, int delta) {
        if (l > r) return;
        if (l == tl and r == tr) {
            ladd[v] += delta, t[v] += (tr - tl + 1) * delta;
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(tm, r), delta), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, delta);
        pull(v);
    }
    int query_sum(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl and r == tr) return t[v];
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return query_sum(2 * v, tl, tm, l, min(r, tm)) + query_sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int l, int r, int delta) {
        update(1, 1, n, l, r, delta);
    }

    int query_sum(int l, int r) {
        return query_sum(1, 1, n, l, r);
    }
};

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    int m;
    cin >> m;
    vector<int> x(m + 1), y(m + 1);

    lazyseg_sum tree(w);

    vector<int> minx(w + 1), miny(h + 1);
    fill(minx.begin(), minx.end(), h + 1);
    fill(miny.begin(), miny.end(), w + 1);

    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
        minx[y[i]] = min(minx[y[i]], x[i]);
        miny[x[i]] = min(miny[x[i]], y[i]);
    }

    int ans = 0;
    vector<vector<int>> to_remove(h + 2);
    for (int i = 1; i <= w; i++) {
        if (minx[i] == 1) break;
        tree.update(i, i, 1);
        to_remove[minx[i]].pb(i);
        ans += (minx[i] - 1);
    }
    for (int i = 1; i <= h; i++) {
        for (int idx: to_remove[i]) {
            tree.update(idx, idx, -1);
        }
        if (miny[i] == 1) break;
        ans += miny[i] - 1;
        ans -= tree.query_sum(1, miny[i] - 1);
    }
    cout << ans << "\n";
} 