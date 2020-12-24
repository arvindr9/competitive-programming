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

int t;

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        vector<int> minx(10), maxx(10), miny(10), maxy(10);
        for (int i = 0; i < 10; i++) {
            minx[i] = miny[i] = 5000;
            maxx[i] = maxy[i] = -5000;
        }
        for (int i = 0; i < n; i++) {
            string st;
            cin >> st;
            for (int j = 0; j < n; j++) {
                a[i][j] = st[j] - '0';
                int val = a[i][j];
                minx[val] = min(minx[val], i);
                maxx[val] = max(maxx[val], i);
                miny[val] = min(miny[val], j);
                maxy[val] = max(maxy[val], j);
            }
        }
        vector<int> opt(10);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // cout << "i: " << i << " , j: " << j << "\n";
                int val = a[i][j];
                // cout << "val: " << val << "\n";
                // cout << "opt[val]: " << opt[val] << "\n"; 
                // if (val == 2) {
                //     cout << "minx: " << minx[val] << ", maxx: " << maxx[val] << ", miny: " << miny[val] << ", maxy: " << maxy[val] << "\n";
                // }
                //left
                opt[val] = max(opt[val], i * (j - miny[val]));
                opt[val] = max(opt[val], i * (maxy[val] - j));
                // if (val == 2) { 
                // cout << "left\n";
                // cout << "opt[val]: " << opt[val] << "\n"; 
                // }
                //right
                opt[val] = max(opt[val], (n - i - 1) * (j - miny[val]));
                opt[val] = max(opt[val], (n - i - 1) * (maxy[val] - j));
                // if (val == 2) {
                // cout << "right\n";
                // cout << "opt[val]: " << opt[val] << "\n"; 
                // }
                //up
                opt[val] = max(opt[val], j * (i - minx[val]));
                opt[val] = max(opt[val], j * (maxx[val] - i));
                // if (val == 2) {
                // cout << "up\n";
                // cout << "opt[val]: " << opt[val] << "\n"; 
                // }
                //down
                opt[val] = max(opt[val], (n - j - 1) * (i - minx[val]));
                opt[val] = max(opt[val], (n - j - 1) * (maxx[val] - i));
                // if (val == 2) {
                // cout << "down\n";
                // cout << "opt[val]: " << opt[val] << "\n"; 
                // }
                // cout << "i: " << i << ", j: " << j << ": val: " << val << ", opt val: " << opt[val] << "\n";
            }
        }
        for (int i = 0; i <= 9; i++) {
            cout << opt[i] << " ";
        }
        cout << "\n";
        
        
    }
} 