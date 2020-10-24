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
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> delta(n);
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            char a; cin >> a;
            if (a == '<') delta[i] = -1;
            else if (a == '>') delta[i] = 1;
            else delta[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int prev_spot = i - 1;
            if (prev_spot < 0) prev_spot += n;
            int next_spot = i + 1;
            if (next_spot >= n) next_spot -= n;
            if (delta[prev_spot] == 0 or delta[prev_spot] == -1) { //move left
                if (delta[prev_spot] == 0) {
                    ret[i] = 1;
                }
            }
            if (delta[i] == 0 or delta[i] == 1) { //move right
                if (delta[i] == 0) {
                    ret[i] = 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += ret[i];
        }
        //check if you can go clockwise
        int num_right = 0;
        for (int i = 0; i < n; i++) {
            if (delta[i] >= 0) num_right++;
        }
        if (num_right == n) ans = n;
        //check if ccw
        int num_left = 0;
        for (int i = 0; i < n; i++) {
            if (delta[i] <= 0) num_left++;
        }
        if (num_left == n) ans = n;
        cout << ans << "\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/