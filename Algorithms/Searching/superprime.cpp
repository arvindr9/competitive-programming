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

bool isPrime(ll n) {
    if(n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
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
    solve(0, 0);
}
