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

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int b, br, bs, a, as;
    cin >> b >> br >> bs >> a >> as;
    int bmoney = (br - b) * bs;
    // a + floor(bmoney / as) + 1
    int ans = a + (bmoney / as) + 1;
    cout << ans << "\n";
} 