#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;

typedef int int2;
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define all(x) x.begin(), x.end()

mt19937_64 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

const int maxn = 1e6 + 5;
int t;
int n;


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        string st;
        cin >> st;
        string ans;
        string last;
        vector<char> bad = {'b','u','g','y','r','t'};
        for (char i: bad) {
            for (int j = 0; j < n; j++) {
                if (st[j] == i) {
                    ans += i;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            bool isbad = false;
            for (int j: bad) {
                if (st[i] == j) {
                    isbad = true;
                }
            }
            if (!isbad) {
                ans += st[i];
            }
        }
        cout << ans << "\n";
        
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/