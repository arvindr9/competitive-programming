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

int solve(int n, int k) {
    // cout << "n: " << n << ", k: " << k << "\n";
    if (n <= k) {
        return n;
    }
    if (n == 2) { // k = 1 here
        return 1;
    }
    int numk = n / k;
    int left = n % k;
    int ans = k - 2;
    int num_apples = 2 * numk;
    // cout << "num_apples: " << num_apples << "\n";
    // cout << "ans: " << ans << "\n";
    if (left > n - 2) num_apples += (left - (n - 2));
    return ans + solve(num_apples, k);
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    // first km is for free
    // int ans = 1 + solve(n, k);

    // cout << ans << "\n";

    int ans = 1;
    while (n > 0) {
        int numk = n / k;
        int left = n % k;
        n -= numk;
        if (left) n--;
        ans++;
    }
    cout << ans << "\n";



    
} 