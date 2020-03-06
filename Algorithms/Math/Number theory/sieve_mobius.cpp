#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e7;

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