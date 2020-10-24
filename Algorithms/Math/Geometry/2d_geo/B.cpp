#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double T;


typedef complex<T> pt;
#define x real()
#define y complex()

#ifndef M_PI
    #define M_PI 3.14159265358979
#endif


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("angle2.in", "r", stdin);
    freopen("angle2.out", "w", stdout);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    T angle1 = atan2(y1, x1);
    T angle2 = atan2(y2, x2);
    if (angle1 < 0) {
        angle1 += (T)2 * (T)M_PI;
    }
    if (angle2 < 0) {
        angle2 += (T)2 * (T)M_PI;
    }
    T max_angle = max(angle1, angle2);
    T min_angle = min(angle1, angle2);
    T ans = max_angle - min_angle;
    // cout << "ans: " << ans << "\n";
    if (ans > (T)M_PI) {
        ans = (T)2 * (T)M_PI - ans;
    }
    cout << setprecision(15) << fixed << ans << "\n";
}