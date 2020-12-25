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
const int inf = 1e18;

const int maxn = 1e3 + 5;
char a[maxn][maxn];
int minvisit[maxn][maxn];
int minmanh[maxn][maxn];
int maxrem[maxn][maxn];
int n, D;

bool valid(int i, int j) {
    if (min(i, j) < 1 or max(i, j) > n or a[i][j] == '#') return false;
    return true;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("rep.out", "w", stdout);
    cin >> n >> D;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            minvisit[i][j] = minmanh[i][j] = inf;
        }
    }

    queue<pi> manhq;
    queue<pi> bfsq0;
    // cout << "n: " << n << ", D: " << D << "\n";


    for (int i = 1; i <= n; i++) {
        string st;
        cin >> st;
        for (int j = 1; j <= n; j++) {
            a[i][j] = st[j - 1];
            if (a[i][j] == '#') {
                minmanh[i][j] = -1; // can expand -1 units out
                // cout << "i: " << i << ", j: " << j << "\n";
                manhq.emplace(i, j);
            } else if (a[i][j] == 'S') {
                minvisit[i][j] = 0;
                bfsq0.emplace(i, j);
            }
        }
    }

    // compute min amount of manhattan distance you can expand from any particular location

    while (!manhq.empty()) {
        auto [i, j] = manhq.front();
        manhq.pop();
        // cout << "i: " << i << ", j: " << j << "\n";
        int curdist = minmanh[i][j];
        for (auto &[i2, j2]: {mp(i - 1, j), mp(i + 1, j), mp(i, j - 1), mp(i, j + 1)}) {
            if (valid(i2, j2)) {
                if (minmanh[i2][j2] > curdist + 1) {
                    minmanh[i2][j2] = curdist + 1;
                    manhq.emplace(i2, j2);
                }
            }
        }
    }


    queue<pair<pi, int>> bfsq1;

    // bfs

    // see what happens to (3, 4)

    while (!bfsq0.empty()) {
        auto [i, j] = bfsq0.front();
        bfsq0.pop();
        int curdist = minvisit[i][j];
        int manh_cap = curdist / D;
        if (minmanh[i][j] < manh_cap) continue;
        // cout << "i: " << i << ", j: " << j << "\n";
        for (auto &[i2, j2]:  {mp(i - 1, j), mp(i + 1, j), mp(i, j - 1), mp(i, j + 1)}) {
            if (valid(i2, j2)) {
                if (minmanh[i2][j2] < manh_cap) continue;
                if (minvisit[i2][j2] > curdist + 1) {
                    // cout << "i2: " << i2 << ", j2: " << j2 << "\n";
                    // cout << "curdist: " << curdist << "\n";
                    minvisit[i2][j2] = curdist + 1;
                    bfsq0.emplace(i2, j2);
                }
            }
        }
        // cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            maxrem[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (minvisit[i][j] < inf) {
                int manh_amt = min(minmanh[i][j], minvisit[i][j] / D);
                bfsq1.emplace(mp(i, j), manh_amt);
                // cout << "i: " << i << ", j: " << j << ", manh_amt: " << manh_amt << "\n";
                // cout << "minvisit: " << minvisit[i][j] << "\n";
                maxrem[i][j] = max(maxrem[i][j], manh_amt);
            }
        }
    }

    while (!bfsq1.empty()) {
        auto [p, rem] = bfsq1.front();
        bfsq1.pop();
        auto [i, j] = p;
        // cout << "i: " << i << ", j: " << j << "rem: " << rem << "\n";
        if (rem == 0) continue;
        for (auto &[i2, j2]: {mp(i + 1, j), mp(i - 1, j), mp(i, j + 1), mp(i, j - 1)}) {
            if (valid(i2, j2)) {
                if (maxrem[i2][j2] < rem) {
                    maxrem[i2][j2] = rem - 1;
                    bfsq1.emplace(mp(i2, j2), rem - 1);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // cout << maxrem[i][j] << " ";
            if (maxrem[i][j] >= 0) {
                // cout << "i: " << i << ", j: " << j << "\n";
                ans++;
            }
        }
        // cout << "\n";
    }
    // cout << "\n";
    cout << ans << "\n";
    
} 