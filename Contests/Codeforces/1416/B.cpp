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
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        int sm = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sm += a[i];
        }
        if (sm % n != 0) {
            cout << -1 << "\n";
            continue;
        }
        int mean = sm / n;
        vector<tuple<int, int, int> > ans;
        //empty a[2...n]
        for (int i = 2; i <= n; i++) {
            int x = i - (a[i] % i);
            if (x == i) x = 0;
            ans.emplace_back(1, i, x);
            a[1] -= x;
            a[i] += x;
            x = a[i] / i;
            ans.emplace_back(i, 1, x);
            a[1] += x * i;
            a[i] -= x * i;
        }
        // make corrections to a[2....n]
        for (int i = 2; i <= n; i++) {
            int x = mean - a[i];
            ans.emplace_back(1, i, x);
            a[i] += x;
            a[1] -= x;
        }

        cout << (3 * n - 3) << "\n";
        for (auto u: ans) {
            int i, j, x;
            tie(i, j, x) = u;
            cout << i << " " << j << " " << x << "\n";
        }

    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/