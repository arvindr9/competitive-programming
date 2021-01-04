#include <bits/stdc++.h>

// Standard sieve implementation

using namespace std;

const int maxn = 1e7 + 5;
int primechk[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < maxn; i++) {
        primechk[i] = 1;
    }
    for (int i = 2; i < maxn; i++) {
        for (int j = 2 * i; j < maxn; j += i) {
            primechk[j] = 0;
        }
    }
    for (int i = 1; i < 20; i++) {
        cout << i << " " << primechk[i] << "\n";
    }
}

// mobius

int primechk[maxn], pfac[maxn], mobius[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < maxn; i++) {
        primechk[i] = 1;
        mobius[i] = -1;
    }
    for (int i = 2; i < maxn; i++) {
        if (primechk[i]) {
            pfac[i] = i;
            mobius[i] = -mobius[i];
            for (int j = 2 * i; j < maxn; j += i) {
                primechk[j] = 0;
                if (((j / i) % i) == 0) {
                    mobius[j] = 0;
                } else {
                    mobius[j] = -mobius[j];
                }
            }
        }
    }

    for (int i = 1; i <= 20; i++) {
        cout << i << " " << mobius[i] << "\n";
    }
}

// pfac

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

// totient

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