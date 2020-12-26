// IDI Open 2017 C

// https://cp-algorithms.com/others/josephus_problem.html

#include <bits/stdc++.h>

using namespace std;


int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
      res = (res + k) % i;
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    int ans = josephus(n, k);
    cout << ans << "\n";
}