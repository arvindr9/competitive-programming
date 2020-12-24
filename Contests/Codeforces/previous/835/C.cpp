#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define pi pair<int, int>
#define all(x) x.begin(), x.end()

int n, q, c;
const int maxn = 1e5 + 5;
int s[maxn];
int x[maxn], y[maxn];
map<int, vector<int>> ys[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> c;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> s[i];
        for (int j = 0; j <= c; j++) {
            ys[j][x[i]]
        }
    }
    

    for (int k = 0; k <= c; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                sm[i][j][k] = sm[i - 1][j][k] + sm[i][j - 1][k] - sm[i - 1][j - 1][k];
            }
        }
    }

    for (int qq = 1; qq <= q; qq++) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= (c + 1);
        // x1 = lower_bound(indx.begin(), indx.end(), mp(x1, -1e6)) - indx.begin();
        // y1 = lower_bound(indy.begin(), indy.end(), mp(y1, -1e6)) - indy.begin();

        // x2 = lower_bound(indx.begin(), indx.end(), mp(x2, 1e6)) - indx.begin()) - 1;
        // y2 = lower_bound(indy.begin(), indy.end(), mp(y2, 1e6)) - indy.begin()) - 1;
        int ans = 0;
        if (min(x1, y1) >= 1 and max(x2, y2) <= n and x1 <= y1 and x2 <= y2) {
            ans = sm[x2][y2][t] - sm[x1 - 1][y1][t] - sm[x1][y2 - 1][t] + sm[x1 - 1][y1 - 1][t];
        }
        cout << ans << "\n";

    }

}