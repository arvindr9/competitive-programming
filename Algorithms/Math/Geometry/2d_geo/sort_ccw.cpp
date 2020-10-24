/*
Verified by https://judge.yosupo.jp/problem/sort_points_by_argument
*/
#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

typedef int int2;
#define int long long

const int maxn = 1e6 + 5;
int t;

typedef long double T;
typedef complex<T> pt;
#define x real()
#define y imag()
#define EPS 1e-9

bool cmp(const pt& p1, const pt& p2) {
    return atan2(p1.y, p1.x) < atan2(p2.y, p2.x);
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pt> pts(n);
    for (int i = 0; i < n; i++) {
        T xx, yy;
        cin >> xx >> yy;
        pts[i] = {xx, yy};
    }
    sort(pts.begin(), pts.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << setprecision(0) << fixed << pts[i].x << " " << pts[i].y << "\n";
    }
    
}