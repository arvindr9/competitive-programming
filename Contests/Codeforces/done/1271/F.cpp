// 1271 F
#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

void print(vector<int> &ans) {
    for (int elt: ans) {
        cout << elt << " ";
    }
    cout << "\n";
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // math, programming, pe
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        int b1, b2, b3;
        cin >> b1 >> b2 >> b3;
        int d1, d2, d3, d4, d5, d6, d7;
        cin >> d1 >> d2 >> d3 >> d4 >> d5 >> d6 >> d7;
        vector<int> ds = {d1, d2, d3, d4, d5, d6, d7};
        d1 = ds[0], d2 = ds[1], d3 = ds[4], d4 = ds[2], d5 = ds[3], d6 = ds[5], d7 = ds[6];
        int maxd1 = min({a1, a2, a3, d1});
        int maxd2 = min({a1, a2, d2});
        if (d1 + (d2 + d4) + d5 > a1 + b1 or d1 + (d2 + d3) + d6 > a2 + b2 or d1 + (d3 + d4) + d7 > a3 + b3) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> ans;
        for (int d11 = 0; d11 <= maxd1; d11++) {
            for (int d21 = 0; d21 <= maxd2; d21++) {
                if (d11 > min({a1, a2, a3}) or d11 + d21 > min(a1, a2)) continue;
                int d12 = d1 - d11;
                int d22 = d2 - d21;
                if (d12 > min({b1, b2, b3}) or d12 + d22 > min(b1, b2)) continue;
                // check satisfiability now
                // d11 + d21 + d31 <= a2
                // d11 + d31 + d41 <= a3
                // d11 + d41 + d21 <= a1

    //             // d31 <= min(a2 - (d11 + d21), a3 - d11) -- covers d2 and d3
    //             // d41 <= min(a1 - (d11 + d21), a3 - d11) -- covers d3 and d1
    //             // d31 + d41 <= a3 - d11

    //             // d32 <= min(b2 - (d12 + d22), b3 - d12)
    //             // d42 <= min(b1 - (d12 + d22), b3 - d12)
    //             // d32 + d42 <= b3 - d12

    //             // d3 <= min(a2 - (d11 + d21), a3 - d11) + min(b2 - (d12 + d22), b3 - d12)
    //             // d4 <= min(a1 - (d11 + d21), a3 - d11) + min(b1 - (d12 + d22), b3 - d12)
    //             // d3 + d4 <= (a3 - d11) + (b3 - d12)

    //             // if above constraint is satisfied for (d3, d4), then extract d31, d32, d41, d42 -- this will only run once i think so we can brute this
                int m1 = min(a2 - (d11 + d21), a3 - d11);
                int m2 = min(a1 - (d11 + d21), a3 - d11);
                int m3 = a3 - d11;
                int m4 = min(b2 - (d12 + d22), b3 - d12);
                int m5 = min(b1 - (d12 + d22), b3 - d12);
                int m6 = b3 - d12;

                if (d3 > m1 + m4) continue;
                if (d4 > m2 + m5) continue;
                if (d3 + d4 > m3 + m6) continue;

                for (int d31 = 0; d31 <= min(m1, d3); d31++) {
                    for (int d41 = 0; d41 <= min(m2, d4); d41++) {
                        if (d31 + d41 > m3) continue;
                        int d32 = d3 - d31;
                        int d42 = d4 - d41;
                        if (d32 > m4) continue;
                        if (d42 > m5) continue;
                        if (d32 + d42 > m6) continue;
                        int d51 = min(d5, a1 - d11 - d21 - d41);
                        int d61 = min(d6, a2 - d11 - d21 - d31);
                        int d71 = min(d7, a3 - d11 - d31 - d41);
                        ans = {d11, d21, d41, d51, d31, d61, d71};
                        goto after;
                    }
                }
        }
    }
    cout << -1 << "\n";
    continue;
    after: print(ans);
    }
}
