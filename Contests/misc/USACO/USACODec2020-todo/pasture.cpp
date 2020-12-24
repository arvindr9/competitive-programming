// TODO

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

const int maxn = 205;
pi coords[maxn];
vector<pi> diag[maxn];


int compress(int elt, vector<int> &v) {
    return lower_bound(v.begin(), v.end(), elt) - v.begin();
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> xs;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        xs.pb(x);
        coords[i] = {x, y};
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    xs.pb(xs.back());
    int nn = xs.size();
    for (int i = nn - 1; i > 0; i--) xs[i] = xs[i - 1];
    xs[0] = -inf;
    xs.pb(+inf);

    vector<vector<vector<int>>> ys(nn + 1, vector<vector<int>>(nn + 1));
    vector<vector<pair<vector<int>, vector<int>>>> endpts(nn + 1, vector<pair<vector<int>, vector<int>>>(nn + 1));
    vector<vector<int>> maxsep(nn + 1, vector<int>(nn + 1));

    for (int i = 1; i <= n; i++) {
        pi coord = coords[i];
        int curi = compress(coords[i].f, xs);
        for (int j = 1; j <= curi; j++) {
            for (int k = curi; j <= nn; k++) {
                ys[j][k].pb(coords[i].s);
            }
        }
        for (int j = 1; j <= curi; j++) {
            endpts[j][curi].s.pb(coords[i].s);
        }
        for (int j = curi; j <= nn; j++) {
            endpts[cur][i].f.pb(coords[i].s);
        }
    }

    for (int i = 1; i <= nn; i++) {
        for (int j = i; j <= nn; j++) {
            sort(ys[i][j].begin(), ys[i][j].end());
            sort(endpts[i][j].f.begin(), endpts[i][j].f.end());
            sort(endpts[i][j].s.begin(), endpts[i][j].s.end());
            maxsep[i][j] = min(+inf, xs[j + 1] - xs[i - 1] - 1);
        }
    }

    // int ans = 1;

    // for (int i = 1; i <= nn; i++) {
    //     for (int j = 1; j <= nn; j++) {
    //         vector<int> elts = ys[i][j];
    //         if (elts.empty()) continue;
    //         int mxsep = maxsep[i][j];
    //         // process elements that contain something in xs[i] and xs[j]
    //     }
    // }




} 