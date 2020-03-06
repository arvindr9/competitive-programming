#include <bits/stdc++.h>

// sieve method from prime factorization

using namespace std;

const int maxn = 1e7 + 5;

int primechk[maxn], primefac[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < maxn; i++) {
        primechk[i] = 1;
        primefac[i] = i;
    }
    for (int i = 2; i < maxn; i++) {
        if (primechk[i]) {
            for (int j = 2 * i; j < maxn; j += i) {
                primefac[j] = i;
                primechk[j] = 0;
            }
        }
    }
    for (int i = 1; i <= 20; i++) {
        int k = i;
        cout << i << " ";
        while (k > 1) {
            cout << primefac[k] << " ";
            k /= primefac[k];
        }
        cout << "\n";
    }
}