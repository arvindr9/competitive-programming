// Source: https://open.kattis.com/problems/kinversions

#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert) {
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
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v, a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd &x: a) x /= n;
    }
}

vector<int> convolve(vector<int> &p, vector<int> &q) {
    vector<cd> f(p.begin(), p.end());
    vector<cd> g(q.begin(), q.end());
    int n = 1;
    while (n < (int)f.size() + (int)g.size()) n <<= 1;
    f.resize(n), g.resize(n);
    cout << "n size: " << n << "\n";
    fft(f, false);
    fft(g, false);
    for (int i = 0; i < n; i++) {
        f[i] *= g[i];
    }
    fft(f, true);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = round(f[i].real());
    }
    return ans;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int pivot = 1 << 20;
    vector<int> p(2 * pivot), q(2 * pivot);
    vector<int> res = convolve(p, q);
}