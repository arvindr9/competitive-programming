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

const int maxn = 2e5 + 5;
int a[maxn];
int prefsum[maxn];
// int prefmin[maxn];
int prefmax[maxn];

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int pos = 0;
    int maxpos = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefsum[i] = prefsum[i - 1] + a[i];
        prefmax[i] = max(prefmax[i - 1], prefsum[i]);
        // prefmin[i] = min(prefmin[i], prefmin[i - 1]);
        maxpos = max(maxpos, pos + prefmax[i]);
        pos += prefsum[i];
    }
    cout << maxpos << "\n";
}