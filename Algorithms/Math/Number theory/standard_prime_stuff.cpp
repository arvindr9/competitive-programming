#include <bits/stdc++.h>

using namespace std;

//untested, I plan to update when tested
typedef int int2;
#define int long long

typedef long long ll;

const ll mod = 1e9 + 7;
const int maxp = 1e6 + 5;

inline int reduce(int a) {
    return (a %= mod) < 0 ? a + mod : a;
}

inline int add(int a, int b) {
    return reduce(a + b);
}

inline int prod(int a, int b) {
    return reduce(a * b);
}

inline int modpow(int a, int pw) {
    if (pw == 0) return 1;
    if (pw % 2 == 0) {
        int res = modpow(a, pw / 2);
        return prod(res, res);
    }
    return prod(a, modpow(a, pw - 1));
}

inline int inv(int a) {
    return modpow(a, mod - 2);
}
int fact[maxp];

inline int binom(int a, int b) {
    if (b > a) return 0;
    int num = fact[a];
    int den = prod(fact[b], fact[a - b]);
    return prod(num, inv(den));
}

inline int cayley(int num, int s) {
    if (num == s) return 1;
    int a1 = modpow(num, num - s - 1);
    return prod(s, a1);
}

ll process_fac() {
  fact[0] = 1;
  for (int i = 1; i < maxp; i++) {
    fact[i] = prod(fact[i - 1], i);
  }
}

ll binom(ll a, ll b) {
  ll num = fac[a];
  ll den = prod(fac[a - b], fac[b]);
  return prod(num, inv(den));
}

vector<int> get_divisors(int a) {
  vector<int> ans = {};
  for (int i = 1; i * i <= a; i++) {
    if (i * i != a) {
      ans.pb(a / i);
    }
    ans.pb(i);
  }
  sort(ans.begin(), ans.end());
  return ans;
}

map<ll, int> pfac(ll a) {
  map<ll, int> res;
  for (int i = 2; i * i <= a; i++) {
    while (a % i == 0) {
      res[i]++;
      a /= i;
  }
  if (a > 1) {
    res[a]++;
  }
  return res;
}

