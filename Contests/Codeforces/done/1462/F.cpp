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

struct lazy_segtree_max {
    int n;
    vector<int> t;
    vector<int> ladd;
    int thresh;
    lazy_segtree_max(int _n) {
        n = _n;
        t.resize(4 * n + 5);
        ladd.resize(4 * n + 5);
        thresh = 0;
    }
    void pull(int v) {
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
    void push(int v) {
        t[2 * v] += ladd[v];
        t[2 * v + 1] += ladd[v];
        ladd[2 * v] += ladd[v];
        ladd[2 * v + 1] += ladd[v];
        ladd[v] = 0;
    }


    int query_max(int v, int tl, int tr, int l, int r) {
        thresh++;
        if (l > r) return 0;
        if (l == tl and r == tr) return t[v];
        int tm = (tl + tr) / 2;
        push(v);
        return max(query_max(2 * v, tl, tm, l, min(tm, r)), query_max(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
    }

    void update(int v, int tl, int tr, int l, int r, int delta) {
        if (l > r) return;
        if (l == tl and r == tr) {
            t[v] += delta;
            ladd[v] += delta;
        } else {
            int tm = (tl + tr) / 2;
            push(v);
            update(2 * v, tl, tm, l, min(tm, r), delta);
            update(2 * v + 1, tm + 1, tr, max(tm + 1, l), r, delta);
            pull(v);
        }
    }

    int query_max(int l, int r) {
        int res = query_max(1, 0, n - 1, l, r);
        return res;
    }

    void update(int l, int r, int delta) {
        update(1, 0, n - 1, l, r, delta);
    }
};



int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pi> segs;
        for (int i = 1; i <= n; i++) {
            int l, r;
            cin >> l >> r;
            segs.eb(l, r);
        }
        sort(segs.begin(), segs.end(), [&](auto u, auto v) {return u.s < v.s;});

        set<pi> elts; // right endpt, index

        lazy_segtree_max seg(n);

        for (int i = 0; i < n; i++) {
            auto leftmost = elts.lower_bound({segs[i].f, -inf});
            if (leftmost != elts.end()) {
                seg.update(leftmost->s, i - 1, +1);
                int num_updates = i - leftmost->s;
                seg.update(i, i, num_updates);
            }
            elts.insert({segs[i].s, i});
        }

        int ans = seg.query_max(0, n - 1);
        ans = n - ans - 1;
        cout << ans << "\n";
    }
        
} 