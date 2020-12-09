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



int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> freq(n + 1);
        vector<int> pos(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            freq[a[i]]++;
            pos[a[i]] = i;
        }
        int l = 1;
        int r = n;
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; i++) {
            if (freq[i] > 1) {
                ans[n + 1 - i] = 1;
                break;
            }
            if (freq[i] == 0) {
                // i cannot occur in the permutation
                break;
            }
            //freq[i] is exactly 1
            if (pos[i] > l and pos[i] < r) {
                ans[n + 1 - i] = 1;
                break;
            }
            if (pos[i] == l) {
                l++;
            } else {
                r--;
            }
            ans[n + 1 - i] = 1;
        }
        //check if original sequence is a permutation
        bool all_once = true;
        for (int i = 1; i <= n; i++) {
            if (freq[i] != 1) {
                all_once = false;
            }
        }
        if (all_once) {
            ans[1] = 1;
        } else {
            ans[1] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i];
        }
        cout << "\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/