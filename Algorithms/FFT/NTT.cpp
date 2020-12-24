#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long


// NTTmod: 998244353(2^23*7*17,3),754974721(2^24*3^2*5,11),469762049(2^26*7,3),167772161(2^25*5,3)

const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;

int reduce(int a) {
    return (a %= mod) < 0 ? a + mod : a;
}

int prod(int a, int b) {
    return reduce(a * b);
}

int add(int a, int b) {
    return reduce(a + b);
}

int modpow(int a, int pw) {
    if (pw == 0) return 1;
    if (pw % 2 == 0) {
        int res = modpow(a, pw / 2);
        return prod(res, res);
    }
    return prod(modpow(a, pw - 1), a);
}

void ntt(vector<int> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wn = invert ? root : root1;
        for (int i = len; i < root_pw; i <<= 1) wn = prod(wn, wn);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j], v = prod(w, a[i + j + len / 2]);
                a[i + j] = add(u, v);
                a[i + j + len / 2] = add(u, -v);
                w = prod(w, wn);
            }
        }
    }
    if (invert) {
        for (int &x: a) {
            x = prod(x, inv(n));
        }
    }
}

vector<int> convolve(vector<int> p, vector<int> q) {
    int n = 1;
    while (n < (int)p.size() + (int)q.size()) {
        n <<= 1;
    }
    p.resize(n), q.resize(n);
    fft(p, false);
    fft(q, false);
    for (int i = 0; i < n; i++) {
        p[i] = prod(p[i], q[i]);
    }
    fft(p, true);
    return p;
}