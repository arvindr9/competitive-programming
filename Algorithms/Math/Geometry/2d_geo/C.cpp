#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double T;


typedef complex<T> pt;
#define x real()
#define y imag()

#ifndef M_PI
    #define M_PI 3.14159265358979
#endif

T double_area(vector<pt> &pts) {
    int n = pts.size();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int j1 = (i + 1) % n;
        int j2 = (i - 1) % n;
        if (j2 < 0) j2 += n;
        ans += pts[i].x * pts[j1].y;
        // cout << "ans: " << ans << "\n";
        ans -= pts[i].x * pts[j2].y;
        // cout << "ans: " << ans << "\n";
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("area.in", "r", stdin);
    freopen("area.out", "w", stdout);
    int n;
    cin >> n;
    vector<pt> pts(n);
    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        pts[i] = pt(xi, yi);
    }
    T pre_ans = double_area(pts);
    T ans = pre_ans / (T)2;
    if (ans < 0) ans *= (T)(-1);
    cout << setprecision(15) << fixed << ans << "\n";
    
}