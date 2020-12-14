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

int n;
const int maxn = 1e5 + 5;
int x[maxn], y[maxn];

void preprocess(vector<int> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int compress(int val, vector<int> &v) {
    return lower_bound(v.begin(), v.end(), val) - v.begin();
}

int t[4 * maxn], lmax[4 * maxn];

void pull(int v) {
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

void push(int v) {
    t[2 * v] = max(t[2 * v], lmax[v]);
    t[2 * v + 1] = max(t[2 * v + 1], lmax[v]);
    lmax[2 * v] = max(lmax[2 * v], lmax[v]);
    lmax[2 * v + 1] = max(lmax[2 * v + 1], lmax[v]);
    lmax[v] = 0;
}

void update(int v,  int tl, int tr, int l, int r, int newmax) {
    if (l > r) return;
    if (l == tl and r == tr) {
        t[v] = max(t[v], newmax);
        lmax[v] = max(lmax[v], newmax);
    } else {
        int tm = (tl + tr) / 2;
        push(v);
        update(2 * v, tl, tm, l, min(r, tm), newmax);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, newmax);
        pull(v);
    }
}

int query_max(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl and r == tr) return t[v];
    int tm = (tl + tr) / 2;
    push(v);
    return max(query_max(2 * v, tl, tm, l, min(r, tm)), query_max(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int i, int newmax) {
    update(1, 0, n, i, n, newmax);
}

int query_max(int i) {
    return query_max(1, 0, n, i, i);
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int xh, yh, xw, yw;
    cin >> xh >> yh >> xw >> yw;
    bool flipx = false;
    bool flipy = false;
    if (xw < xh) flipx = true;
    if (yw < yh) flipy = true;
    vector<int> xs;
    vector<int> ys;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    if (flipx) {
        xh = -xh;
        xw = -xw;
        for (int i = 1; i <= n; i++) {
            x[i] = -x[i];
        }
    }

    if (flipy) {
        yh = -yh;
        yw = -yw;
        for (int i = 1; i <= n; i++) {
            y[i] = -y[i];
        }
    }

    xs.pb(xh);
    xs.pb(xw);
    ys.pb(yh);
    ys.pb(yw);
    vector<int> realx;
    vector<int> realy;
    for (int i = 1; i <= n; i++) {
        if (xh <= x[i] and x[i] <= xw) {
            if (yh <= y[i] and y[i] <= yw) {
                realx.pb(x[i]);
                realy.pb(y[i]);
                xs.pb(x[i]);
                ys.pb(y[i]);
            }
        }
    }
    preprocess(xs);
    preprocess(ys);
    int numreal = realx.size();
    for (int i = 0; i < numreal; i++) {
        realx[i] = compress(realx[i], xs);
        realy[i] = compress(realy[i], ys);
    }
    xh = compress(xh, xs); //this will be zero
    xw = compress(xw, xs);
    yh = compress(yh, ys);
    yw = compress(yw, ys);
    vector<pi> points;
    for (int i = 0; i < numreal; i++) {
        points.eb(realx[i], realy[i]);
    }
    sort(points.begin(), points.end());
    for (auto &[xx, yy]: points) {
        int curans = query_max(yy);
        update(yy, curans + 1);
    }
    int ans = query_max(yw);
    cout << ans << "\n";
} 