// CF 876 F

#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define f first
#define s second

const int inf = 1e18;

const int maxn = 2e5 + 5;
int t[4 * maxn];
int a[maxn];
int n;

void pull(int v) {
    t[v] = t[2 * v] | t[2 * v + 1];
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        pull(v);
        // cout << "t[v]: " << t[v] << "\n";
    }
}

void build() {
    build(1, 1, n);
}

 ///   a-2  [a-1 a0  [max] a2 a3 a4] a5 a6
struct elt {
    int mx, mxind, l, r;
    elt(int mx, int mxind, int l, int r) : mx(mx), mxind(mxind), l(l), r(r) {}
};

int last_leq(int v, int tl, int tr, int l, int r, int bound, int &accum) {
    if (l > r) return -1;

    if (l == tl and r == tr) {
        if ((accum | t[v]) <= bound) {
            accum |= t[v];
            return r;
        }
        else {
            // check largest prefix that satisfies the bound
            if (tl == tr) {
                return -1;
            } else {
                int tm = (tl + tr) / 2;
                int rr = min(r, tm);
                int ll = max(l, tm + 1);
                int res = -1;

                res = last_leq(2 * v, tl, tm, l, rr, bound, accum);
                if (res < rr) return res;

                res = max(res, last_leq(2 * v + 1, tm + 1, tr, ll, r, bound, accum));
                return res;
            }
        }
    }

    int tm = (tl + tr) / 2;
    int rr = min(tm, r);
    int ll = max(l, tm + 1);

    int res = -1;

    if (tm >= l) {
        res = last_leq(2 * v, tl, tm, l, rr, bound, accum);
        if (res < rr) return res;
    }
    res = max(res, last_leq(2 * v + 1, tm + 1, tr, ll, r, bound, accum));
    return res;
}

int first_leq(int v, int tl, int tr, int l, int r, int bound, int &accum) {
    if (l > r) return inf;

    if (l == tl and r == tr) {
        if ((accum | t[v]) <= bound) {
            accum |= t[v];
            return l;
        }
        else {
            // check largest prefix that satisfies the bound
            if (tl == tr) {
                return inf;
            } else {
                int tm = (tl + tr) / 2;
                int rr = min(r, tm);
                int ll = max(l, tm + 1);
                int res = inf;

                res = first_leq(2 * v + 1, tm + 1, tr, ll, r, bound, accum);
                if (res > ll) return res;

                res = min(res, first_leq(2 * v, tl, tm, l, rr, bound, accum));
                return res;
            }
        }
    }

    int tm = (tl + tr) / 2;
    int rr = min(tm, r);
    int ll = max(l, tm + 1);

    int res = inf;

    if (tm + 1 <= r) {
        res = first_leq(2 * v + 1, tm + 1, tr, ll, r, bound, accum);
        if (res > ll) return res;
    }
    res = min(res, first_leq(2 * v, tl, tm, l, rr, bound, accum));
    return res;
}

int last_leq(int l, int r, int bound) {
    int accum = 0;
    int res = last_leq(1, 1, n, l, r, bound, accum);
    return res;
}

int first_leq(int l, int r, int bound) {
    int accum = 0;
    int res = first_leq(1, 1, n, l, r, bound, accum);
    return res;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<pi> occurrences; // val, idx
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        occurrences.emplace_back(a[i], i);
    }
    build();
    sort(occurrences.begin(), occurrences.end(), [&] (auto u, auto v) {return u.f == v.f ? u.s < v.s : u.f > v.f;});
    set<int> indices;
    vector<elt> elts;
    for (auto &[val, ind]: occurrences) {
        int l, r;
        auto it = indices.lower_bound(ind);
        if (it == indices.begin()) {
            l = 1;
        } else {
            it--;
            l = (*it) + 1;
        }
        indices.insert(ind);
        it = indices.upper_bound(ind);
        if (it == indices.end()) {
            r = n;
        } else {
            r = (*it) - 1;
        }
        elts.eb(val, ind, l, r);
    }

    int ans = 0;

    for (auto &[val, ind, l, r]: elts) {
        int ll = first_leq(l, ind, val);
        ll--;
        int rr = last_leq(ind, r, val);
        rr++;
        if (ll >= l) {
            ans += (ll - l + 1) * (r - ind + 1);
        }
        if (rr <= r) {
            ans += (r - rr + 1) * (ind - l + 1);
        }
        if (ll >= l and rr <= r) {
            ans -= (ll - l + 1) * (r - rr + 1);
        }
    }
    cout << ans << "\n";

}
