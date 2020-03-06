#include <bits/stdc++.h>

// sieve method for totient. Based on the idea that \sum_{d|n} phi(d) = n

using namespace std;

const int maxn = 1e7 + 5;

int primechk[maxn], phi[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        primechk[i] = 1;
        phi[i] = i;
    }
    for (int i = 2; i < maxn; i++) {
        if (primechk[i]) {
            phi[i] -= 1;
            for (int j = 2 * i; j < maxn; j += i) {
                primechk[j] = 0;
                phi[j] -= (phi[j] / i);
            }
        }
    }

    for (int i = 1; i <= 30; i++) {
        cout << i << " " << phi[i] << "\n";
    }
}