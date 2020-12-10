#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define f first
#define s second

int n, k;
int calc(int cand) {
        if (cand > n) return 0;
        // keep the last digit
        int cand2 = cand;
        int ans = 0;
        int num_freedom = 0;
        while ((cand2 << 1) <= n) {
            cand2 <<= 1;
            num_freedom++;
        }
        for (int i = 0; i < num_freedom; i++) {
            ans += (1LL << i);
        }

        // check if cand is a prefix of n -- this will run only if num_freedom > 0
        if ((n >> num_freedom) == cand) {
            // count num ways to make cand + [num_freedom digits]
            for (int i = num_freedom - 1; i >= 0; i--) {
                if (n & (1LL << i)) {
                    // set bit to zero
                    ans += (1LL << i);
                }
                // otherwise set bit to equal corresponding bit of n (to be enumerated later)
            }
            ans++; //corresponds to matching n
        } else {
            ans += (1LL << num_freedom);
        }

        // change the last digit to 1

        if ((cand & 1LL) == 0) {
            ans += calc(cand ^ 1LL);
        }
        
        return ans;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int ans = 1;
    while (calc(ans << 1) >= k) {
        ans <<= 1;
    }
    for (int i = 59; i >= 0; i--) {
        if (calc(ans|(1LL<<i)) >= k) {
            ans |= (1LL << i);
        }
    }
    cout << ans << "\n";

}