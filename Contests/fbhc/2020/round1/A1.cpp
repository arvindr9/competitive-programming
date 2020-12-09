#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second

int t;
int n, k, w;
const int maxn = 1e6 + 5;
int L[maxn], H[maxn];
const int mod = 1e9 + 7;

void printcase(int tt, int ans) {
    cout << "Case #" << tt << ": " << ans << "\n";
}

int reduce(int a) {
    return (a %= mod) < 0 ? a + mod : a;
}

int prod(int a, int b) {
    return reduce(a * b);
}

int2 main() {
    // freopen("A.in", "r", stdin);
    freopen("perimetric_chapter_1_input.txt", "r", stdin);
    freopen("A.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cin >> n >> k >> w;
        for (int i = 1; i <= k; i++) {
            cin >> L[i];
        }
        int al, bl, cl, dl;
        cin >> al >> bl >> cl >> dl;
        for (int i = k + 1; i <= n; i++) {
            L[i] = ((al * L[i - 2] + bl * L[i - 1] + cl) % dl) + 1;
        }
        for (int i = 1; i <= k; i++) {
            cin >> H[i];
        }
        int ah, bh, ch, dh;
        cin >> ah >> bh >> ch >> dh;
        for (int i = k + 1; i <= n; i++) {
            H[i] = ((ah * H[i - 2] + bh * H[i - 1] + ch) % dh) + 1;
        }

        int ans = 1;

        int perimeter = 0;

        for (int i = 1; i <= n; i++) {
            //vertical component
            int max_height = 0;
            for (int j = max(1LL, i - w); j < i; j++) {
                if (L[j] + w >= L[i]) max_height = max(max_height, H[j]);
            }
            if (max_height < H[i]) {
                perimeter += 2LL * (H[i] - max_height);
            }
            perimeter %= mod;
            //horizontal component
            if (i == 1 or L[i] > L[i - 1] + w) {
                perimeter += 2LL * w;
            } else {
                perimeter += 2LL * (L[i] - L[i - 1]);
            }
            perimeter %= mod;
            ans = prod(ans, perimeter);
        }

        printcase(tt, ans);
    }
}