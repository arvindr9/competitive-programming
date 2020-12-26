#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long
#define pi pair<int, int>
#define f first
#define s second
#define mp make_pair

// NTT mod: 998244353(2^23*7*17,3)

const int mod = 998244353;
// 3^(2^23 * 7 * 17) = 1
 
int root = 15311432;
int root_pw = 1 << 23;
int root_1 = 469870224;

int reduce(int a) {
    return (a %= mod) < 0 ? a + mod : a;
}

int add(int a, int b) {
    return reduce(a + b);
}

int prod(int a, int b) {
    return reduce(a * b);
}

int modpow(int a, int pw) {
    if (pw == 0) return 1;
    if (pw % 2 == 0) {
        int res = modpow(a, pw / 2);
        return prod(res, res);
    }
    return prod(a, modpow(a, pw - 1));
}

int inv(int a) {
    return modpow(a, mod - 2);
}

void ntt(vector<int> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; bit & j; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1) wlen = prod(wlen, wlen);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j], v = prod(w, a[i + j + len / 2]);
                a[i + j] = add(u, v);
                a[i + j + len / 2] = add(u, -v);
                w = prod(w, wlen);
            }
        }
    }

    if (invert) {
        int invn = inv(n);
        for (auto &x: a) x = prod(x, invn);
    }
}

vector<int> convolve(vector<int> p, vector<int> q) {
    int n = 1;
    while (n < (int)p.size() + (int)q.size()) n <<= 1;
    p.resize(n), q.resize(n);
    ntt(p, false);
    ntt(q, false);
    for (int i = 0; i < n; i++) {
        p[i] = prod(p[i], q[i]);
    }
    ntt(p, true);
    return p;
}

template <class T> struct segtree {
    vector<T> t;
    int n;
    T deft;
    segtree(int n): t(4 * n + 5), n(n), deft(make_pair(0LL, 0LL)) {}
    T f(T a, T b) {
        if (a.f == b.f) {
            if (a.s < b.s) return a;
            else return b;
        }
        return max(a, b);
    }
    void pull(int v) {
        t[v] = f(t[2 * v], t[2 * v + 1]);
    }
    void update(int v, int tl, int tr, int pos, T val) {
        if (tl == tr) {
            t[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2 * v, tl, tm, pos, val);
            } else {
                update(2 * v + 1, tm + 1, tr, pos, val);
            }
            pull(v);
        }
    }

    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return deft;
        if (l == tl and r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return f(query(2 * v, tl, tm, l, min(tm, r)), query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
    }

    void update(int pos, T val) {
        update(1, 0, n, pos, val);
    }

    T query(int l, int r) {
        return query(1, 0, n, l, r);
    }
};


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int maxn = 5e5 + 1;
    vector<int> ab(maxn);
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j * i < maxn; j++) {
            ab[i * j]++;
        }
    }
    vector<int> res = convolve(ab, ab);
    int res_sz = res.size();
    // cout << "ab:\n";
    // for (int i = 1; i <= 5; i++) {
    //     cout << ab[i] << " ";
    // }
    // cout << "\n";
    // cout << "res:\n";
    // for (int i = 1; i <= 5; i++) {
    //     cout << res[i] << " ";
    // }
    // cout << "\n";
    segtree<pi> tree(maxn);
    for (int i = 0; i < maxn; i++) {
        tree.update(i, mp(res[i], i));
    }

    for (int i = 1; i <= n; i++) {
        int alo, ahi;
        cin >> alo >> ahi;
        pi opt = tree.query(alo, ahi);
        cout << opt.s << " " << opt.f << "\n";
    }
}