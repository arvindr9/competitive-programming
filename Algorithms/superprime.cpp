/*
Problem: Superprime Rib (USACO 1994 Final Round, adapted):
A number is called superprime if it is prime and every number
obtained by chopping some number of digits from the right side
of the decimal expansion is prime. For example, 233 is a
superprime, because 233, 23, and 2 are all prime. Print a list of
all the superprime numbers of length n, for n <= 9.
The number 1 is not a prime

Solution: O(n sqrt(n)) -- but not really since there aren't that many superprimes
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll p1 = 1000000007;
const ll p2 = 1000000009;
const ll p3 = 15485867;

ll modpow(ll a, ll p, ll prime) {
    ll res = 1;
    while (p) {
        if(p & 1) {
            res = res * 1LL * a;
            if(res >= prime) res %= prime;
        }
        a = a * 1LL * a;
        if(a >= prime) a %= prime;
        p /= 2;
    }
    return res;
}

bool isPrime(ll n) {
    if(n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
    // if(n == p1 || n == p2 || n == p3) return true;
    // if(n % p1 == 0 || n % p2 == 0 || n % p3 == 0 || n == 1) return false;
    // return modpow(n, p1 - 1, p1) == 1 && modpow(n, p2 - 1, p2) == 1 && modpow(n, p3 - 1, p3) == 1;
}

void solve(ll num, int n) {
    if(n == 10) {
        cout << n << "\n";
        return;
    }
    for(int i = 1; i <= 9; i++) {
        ll new_num = (num * 10) + i;
        if(isPrime(new_num)) {
            cout << new_num << "\n";
            solve(new_num, n + 1);
        }
    }
}

int main() {
    //freopen("superprime.out", "w", stdout);
    
    solve(0, 0);
}