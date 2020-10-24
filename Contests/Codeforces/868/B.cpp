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

int h, m, ss, t1, t2;

int open[13];
int blocked[13];

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> h >> m >> ss >> t1 >> t2;

    for (int i = 1; i <= 12; i++) {
        open[i] = 1;
    }
    if (m == 0 and ss == 0) {
        open[h] = 0;
        int prev_pos = h - 1;
        if (prev_pos == 0) prev_pos += 12;
        blocked[prev_pos] = 1;
    } else {
        blocked[h] = 1;
    }

    if (ss % 5 == 0) {
        int pos = ss / 5;
        if (pos == 0) pos += 12;
        open[pos] = 0;
        int prev_pos = pos - 1;
        if (prev_pos == 0) prev_pos = 12;
        blocked[prev_pos] = 1;
    } else {
        int prev_pos = ss - (ss % 5);
        prev_pos /= 5;
        if (prev_pos == 0) prev_pos = 12;
        blocked[prev_pos] = 1;
    }

    if (m % 5 == 0) {
        int pos = m / 5;
        if (pos == 0) pos += 12;
        if (ss == 0) {
            open[pos] = 0;
            int prev_pos = pos - 1;
            if (prev_pos == 0) prev_pos += 12;
            blocked[prev_pos] = 1;
        } else {
            blocked[pos] = 1;
        }
    } else {
        int pos = m / 5;
        if (pos == 0) pos = 12;
        blocked[pos] = 1;
    }

    // cout << "blocked:\n";
    // for (int i = 1; i <= 12; i++) {
    //     cout << blocked[i] << " ";
    // }
    // cout << "\n";

    if (t1 > t2) swap(t1, t2);
    //clockwise
    int i = t1;
    while (true) {
        // cout << "i1: " << i << "\n";
        if (i == t2) {
            cout << "YES\n";
            return 0;
        }
        if (blocked[i]) break;
        i++;
        i %= 12;
        if (i == 0) i += 12;
    }
    //counterclockwise
    i = t2;
    while (true) {
        // cout << "i2: " << i << "\n";
        if (i == t1) {
            cout << "YES\n";
            return 0;
        }
        if (blocked[i]) break;
        i++;
        i %= 12;
        if (i == 0) i += 12;
    }
    cout << "NO\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/