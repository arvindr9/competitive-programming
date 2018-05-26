//This implementation finds the minimum in an array with elements that are nonincreasing then nondecreasing.

#include <bits/stdc++.h>

using namespace std;
const int INF = INT_MAX/2;

int arr[maxn]

int main() {
    cin >> n;
    for (int i = 1; i<= n; i++) {
        cin >> arr[i];
    }
    int ans = INF;
    int l = 1;
    int r = n;
    while (l <= r) {
        int m1 = (2 * l + r) / 3;
        int m2 = (l + 2 * r) / 3;
        int ans1 = arr[m1];
        int ans2 = arr[m2];
        if (ans1 >= ans2) l = m1 + 1;
        else r = m2 - 1;
        ans = min(ans, min(ans1, ans2));
    }
    cout << ans << "\n"
}
