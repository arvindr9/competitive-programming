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
int n;


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> n;
    vector<pi> ops(2 * n + 1);
    set<int> open;
    vector<int> verdict(2 * n + 1);
    vector<int> idx(n + 1), idx2(n + 1);
    int cursum = 0;
    for (int i = 1; i <= 2 * n; i++) {
        char ch;
        int j;
        cin >> ch;
        if (ch == '-') {
            cin >> j;
            ops[i] = {-1, j};
            idx[j] = i;
            cursum--;
        } else {
            ops[i] = {1, -1};
            cursum++;
        }
        if (cursum < 0) {
            cout << "NO\n";
            return 0;
        }
        if (i > 1 and ops[i].f == -1) {
            if (ops[i].s < ops[i - 1].s) {
                cout << "NO\n";
                return 0;
            }
        }
        if (ops[i - 1].f == 1) open.insert(i - 1);
    }

    for (int i = 1; i <= n; i++) {
        auto it = open.upper_bound(idx[i]);
        it--;
        int last_geq = *it;
        open.erase(it);
        verdict[last_geq] = i;
    }
    // cout << "created verdict\n";
    // for (int i = 1; i <= 2 * n; i++) {
    //     cout << verdict[i] << "\n";
    // }
    vector<int> ans;
    for (int i = 1; i < 2 * n; i++) {
        if (ops[i].f == 1 and ops[i + 1].f == -1) {
            if (ops[i + 1].s != verdict[i]) {
                cout << "NO\n";
                return 0;
            }
        }
        if (ops[i].f == 1) {
            // cout << "i: " << i << ", verdict[i]: " << verdict[i] << "\n";
            ans.pb(verdict[i]);
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/