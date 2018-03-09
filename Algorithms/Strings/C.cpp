#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1000000;
int n, m;
const int p = 107;
set<ll> hashset;
ll x = 234567890;
int poww[maxn];
int inv_pow[maxn];
int dp[maxn];

//hash[l, r] = (dp[r] - dp[l - 1]) * inv_pow[l]

ll modpow(ll a, int p, ll mod) {
    if(p == 0) {
        return 1;
    }
    ll res = 1;
    while (p >= 1) {
        if (p&1) {
            res = (res * a) % mod;
            p -= 1;
        }
        if(p > 0) res = (res * res) % mod;
        p /= 2;
    }
    return res;
}

void constructPow() {
    ll num = 1;
    for(int i = 0; i <= 10000; i++) {
        poww[i] = (int)num;
        num *= x;
        num %= p;
    }
    ll inv = modpow(x, p - 2, p);
    num = 1;
    for(int i = 0; i <= 10000; i++) {
        inv_pow[i] = (int)num;
        num *= inv;
        num %= p;
    }
}

void addToHash(string s) {
    ll hash = 0;
    int len = s.size();
    for(int i = 0; i < len; i++) {
        ll c = s[i] - 'a';
        hash *= x;
        hash += c;
        hash %= p;
        dp[i] = hash;
    }
    hashset.insert(x * (dp[len] - dp[0]));
    for(int i = 1; i < len; i++) {
        ll h1 = dp[i - 1];
        ll h2 = dp[len] - dp[i];
        h2 = (h2 * x) % p;
        hashset.insert(h1 + h2);
    }

}

int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
    }
    for(int q = 1; q <= n; q++) {
        string s;
        cin >> s;
    }

}
