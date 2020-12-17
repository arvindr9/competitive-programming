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

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> k >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> vs(m);
    for (int i = 0; i < n; i++) {
        int md = a[i] % m;
        vs[md].pb(a[i]);
        // cout << "sz: " << vs[md].size() << "\n";
    }
    bool possible = false;
    for (int i = 0; i < m; i++) {
        if ((int)vs[i].size() >= k) {
            possible = true;
            cout << "Yes\n";
            for (int j = 0; j < k; j++) cout << vs[i][j] << " ";
            cout << "\n";
            break;
        }
    }
    if (!possible) {
        cout << "No\n";
    }
} 