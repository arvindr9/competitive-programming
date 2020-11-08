#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second

const int maxn = 1e3 + 5;
int primechk[maxn];
vector<int> primes;

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < maxn; i++) {
        primechk[i] = 1;
    }
    for (int i = 2; i < maxn; i++) {
        if (primechk[i]) {
            primes.pb(i);
            for (int j = 2 * i; j < maxn; j += i) {
                primechk[j] = 0;
            }
        }
    }

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int best_prime = 2;
    int most_div = 0;
    for (int p: primes) {
        int total_div = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] % p == 0) total_div++;
        }
        if (total_div > most_div) {
            most_div = total_div;
            best_prime = p;
        }
    }
    cout << best_prime << "\n";
}