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

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> t;
    // while (t--) {
        int h;
        cin >> h;
        vector<int> a(h + 1);
        for (int i = 0; i <= h; i++) {
            cin >> a[i];
        }
        bool unq = true;
        for (int i = 0; i < h; i++) {
            if (a[i] != 1 and a[i + 1] != 1) unq = false;
        }
        if (unq) {
            cout << "perfect\n";
            return 0;
        }
        vector<int> fst(h + 2);
        fst[0] = 1;
        for (int i = 1; i <= h; i++) {
            fst[i] = fst[i - 1] + a[i - 1];
        }
        // int n = fst[h] + a[h];
        // fst[h + 1] = n;
        fst[h + 1] = fst[h] + a[h];
        // cout << "final fst: " << fst[h + 1] << "\n";
        vector<int> v0;
        vector<int> v1;
        v0.pb(0);
        v1.pb(0);
        for (int i = 1; i <= h; i++) {
            for (int j = fst[i]; j < fst[i + 1]; j++) {
                v0.pb(fst[i - 1]);
            }
            if (a[i] > 1 and a[i - 1] > 1) {
                for (int j = 0; j < a[i]; j++) {
                    v1.pb(fst[i - 1] + (j % a[i - 1]));
                }
            } else {
                for (int j = fst[i]; j < fst[i + 1]; j++) {
                    v1.pb(fst[i - 1]);
                }
            }
        }
        cout << "ambiguous\n";
        for (int elt: v0) {
            cout << elt << " ";
        }
        cout << "\n";
        for (int elt: v1) {
            cout << elt << " ";
        }
        cout << "\n";
    // }
} 