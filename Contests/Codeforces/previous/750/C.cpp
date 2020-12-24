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
    int curr_score = 0;
    int n;
    int max2 = -INF;
    int min1 = INF;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int c, d;
        cin >> c >> d;
        if (d == 1) {
            min1 = min(min1, curr_score);
        }
        if (d == 2) {
            max2 = max(max2, curr_score);
        }
        // cout << "curr_score: " << curr_score << "\n";
        curr_score += c;
    }
    // cout << "max2: " << max2 << "\n";
    // cout << "min1: " << min1 << "\n";
    if (max2 >= min1) {
        cout << "Impossible\n";
    } else {
        if (max2 == -INF) {
            cout << "Infinity\n";
        } else {
            // push max2 to be 1899
            curr_score += (1899 - max2);
            cout << curr_score << "\n";
        }
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/