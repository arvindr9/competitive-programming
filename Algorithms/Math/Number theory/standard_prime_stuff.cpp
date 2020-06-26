#include <bits/stdc++.h>

using namespace std;

//untested, I plan to update when tested

typedef long long ll;

const ll mod = 1e9 + 7;
const int maxp = 200;
ll fac[maxn];

ll reduce(ll a) {
    return ((a % mod) + mod) % mod;
}

ll add(ll a, ll b) {
    return reduce(a + b);
}

ll prod(ll a, ll b) {
    return reduce(a * b);
}

ll modpow(ll a, ll pw) {
    if (pw == 0) return 1;
    if (pw % 2 == 1) return prod(a, modpow(a, pw - 1));
    ll res = modpow(a, pw / 2);
    return prod(res, res);
}

ll inv(ll a) {
    return modpow(a, mod - 2);
}

ll process_fac() {
  fac[0] = 1;
  for (int i = 1; i < maxp; i++) {
    fac[i] = prod(fac[i - 1], i);
  }
}

ll binom(ll a, ll b) {
  ll num = fac[a];
  ll den = prod(fac[a - b], fac[b]);
  return prod(num, inv(den));
}

map<ll, int> pfac(ll a) {
  map<ll, int> res;
  for (int i = 1; i * i <= a; i++) {
    while (a % i == 0) {
      res[i]++;
      a /= i;
  }
  if (a > 1) {
    res[a]++;
  }
  return res;
}

map<ll, int> gcd(map<ll, int> p1, map<ll, int> p2) {
  map<ll, int> res;
  for (pair<int, int> p: p1) {
    res[p.first] = min(p.second, p2[p.first]);
  }
  for (pair<int, int> p: p2) {
    res[p.first] = min(p.second, p1[p.first]);
  }
  return res;
}

