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