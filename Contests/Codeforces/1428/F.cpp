#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;
typedef priority_queue<int, vector<int>, greater<int> > min_heap;

// template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
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
    int n;
    cin >> n;
    string st;
    cin >> st;
    st += '2';
    int add = 0;
    int ans = 0;
    int num_ones = 0;

    vector<int> stk;
    stk.push_back(0);

    for (int i = 0; i <= n; i++) {
        if (st[i] == '1') {
            num_ones++;
        } else { //update stack
            if (i > 0 and st[i - 1] == '1') { //incorporate earlier ones
                // cur height = size of stk
                for (int j = 1; j <= num_ones; j++) {
                    if (stk.size() > 1) {
                        int sz = stk.size();
                        add -= (stk[sz - 1] - stk[sz - 2]) * j;
                        add += (i - num_ones - 1 + j - stk[sz - 2]) + (stk[sz - 1] - stk[sz - 2]) * (j - 1);
                        stk.pop_back();
                        ans += add;
                    } else {
                        add += (i - num_ones - 1 + j + 1);
                        // cout << "add: " << add << "\n";
                        ans += add;
                    }
                }

                for (int j = num_ones; j >= 1; j--) {
                    stk.pb(i - j);
                }
                // cout << "ans: " << ans << "\n";
                if (i < n) ans += add;
                // cout << "ans: " << ans << "\n";
            } else {
                if (i < n) ans += add;
                // cout << "ans: " << ans << "\n";
            }
            num_ones = 0;
        }
    }
    cout << ans << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/