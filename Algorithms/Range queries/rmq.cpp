// https://judge.yosupo.jp/submission/54414

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

int t;

const int ln = 20;

struct rmq {
    int n;
    vector<vector<int>> jmp;
    rmq(vector<int> &a): jmp(1, a) {
        for (int pw = 1, k = 1; pw * 2 <= (int)a.size(); pw *= 2, k++) {
            jmp.eb((int)a.size() - 2 * pw + 1); // last 2 * pw - 1 entries extend past r so ignore them
            for (int j = 0; j < (int)jmp[k].size(); j++) {
                jmp[k][j] = min(jmp[k-1][j], jmp[k-1][j+pw]);
            }
        }
    }
    int query(int l, int r) {
        int log = log2(r - l);
        int pw = 1LL << log;
        return min(jmp[log][l], jmp[log][r - pw]);
    }
};

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    rmq R(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << R.query(l, r) << "\n";
    }

} 

// 2d rmq:

int jmp[ln+1][ln+1][maxn][maxn];
vector<int> two_pows;

void init(vector<vector<int>> arr) {
    int n = (int)arr[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            jmp[0][0][i][j] = arr[i][j];
        }
    }
    two_pows.pb(1);
    for (int i = 1; i <= ln; i++) {
        two_pows.pb(two_pows.back() * 2);
    }
    for (int lul0 = 0; lul0 <= ln; lul0++) {
        for (int lul1 = 0; lul1 <= ln; lul1++) {
            if (lul0 == 0 and lul1 == 0) continue;
            int pw0 = two_pows[lul0];
            int pw1 = two_pows[lul1];
            int half0 = pw0 / 2;
            int half1 = pw1 / 2;
            // i + pw <= n => i <= n - pw
            for (int i = 0; i <= n - pw0; i++) {
                for (int j = 0; j <= n - pw1; j++) {
                    if (lul0 > 0) {
                        jmp[lul0][lul1][i][j] = min(jmp[lul0-1][lul1][i][j], jmp[lul0-1][lul1][i+half0][j]);
                    }
                    else {
                        jmp[lul0][lul1][i][j] = min(jmp[lul0][lul1-1][i][j], jmp[lul0][lul1-1][i][j+half1]);
                    }
                }
            }
        }
    }
}

int query(int a, int b, int c, int d) {
    int lulx = log2(b - a + 1);
    int luly = log2(d - c + 1);
    // cout << "d-c+1: " << d-c+1 << "\n";
    int pwx = two_pows[lulx];
    int pwy = two_pows[luly];
    // cout << "lulx: " << lulx << ", luly: " << luly << "\n";
    return min({jmp[lulx][luly][a][c], jmp[lulx][luly][a][(d+1)-pwy],
    jmp[lulx][luly][(b+1)-pwx][c], jmp[lulx][luly][(b+1)-pwx][(d+1)-pwy]});
}

