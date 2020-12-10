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
#define INF 1e18

int t;
int n, sx, sy;

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> sx >> sy;
    int num_above = 0;
    int num_below = 0;
    int num_left = 0;
    int num_right = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if (x < sx) num_left++;
        if (x > sx) num_right++;
        if (y < sy) num_below++;
        if (y > sy) num_above++;
    }
    int mx = max({num_left, num_right, num_below, num_above});
    if (num_left == mx) {
        cout << num_left << "\n";
        cout << sx - 1 << " " << sy << "\n";
    } else if (num_right == mx) {
        cout << num_right << "\n";
        cout << sx + 1 << " " << sy << "\n";
    } else if (num_below == mx) {
        cout << num_below << "\n";
        cout << sx << " " << sy - 1 << "\n";
    } else if (num_above == mx) {
        cout << num_above << "\n";
        cout << sx << " " << sy + 1 << "\n";
    }
} 