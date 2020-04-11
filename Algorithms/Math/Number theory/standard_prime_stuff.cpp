#include <bits/stdc++.h>

using namespace std;

//untested

typedef long long ll;

const ll mod = 1e9 + 7;
const int maxp = 200;
ll fac[maxn];

ll add(ll a, ll b) {
  return (((a + b) % mod) + mod ) % mod;
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
  ll den = prod(fac[a - b], fac[b])
  return prod(num, inv(den));
}

map<ll, int> pfac(ll a, ll b)
