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
#define inf 1e18

typedef long double T;
typedef complex<T> pt;
#define x real()
#define y complex()

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M, N; T R;
    cin >> M >> N >> R;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dx = abs(x1 - x2); // used for angle
    T theta = (T)dx / (T)M * M_PI;

    T ans = inf;
    for (int i = 0; i <= N; i++) {
        T r = (T)i / (T)N * (T)R;
        T d1 = abs(y1 - i) / (T)N * (T)R;
        T d2 = abs(y2 - i) / (T)N * (T)R;
        T cand = d1 + d2 + r * theta;
        ans = min(ans, cand);
    }
    cout << fixed << setprecision(7) <<  ans << "\n";
} 

