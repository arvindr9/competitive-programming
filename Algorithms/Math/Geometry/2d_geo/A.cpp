#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double T;


typedef complex<T> pt;
#define x real()
#define y complex()

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif


int main() {
    freopen("angle1.in", "r", stdin);
    freopen("angle1.out", "w", stdout);
    int a, b;
    cin >> a >> b;
    T ans = atan2(b, a);
    if (ans < 0) ans += (T)2 * (T)M_PI;
    cout << setprecision(15) << fixed << ans << "\n";
}