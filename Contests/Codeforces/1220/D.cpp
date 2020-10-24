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
const ll INF = 2e18;
const int MX = 100001;

const int maxn = 1e6 + 5;
int t;
int a[maxn];
int n;


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int pw = 1;
    int largest = 0;
    vector<int> remove_best;
    while (pw * 2 < INF) {
        int cur_ans = 0;
        vector<int> cur_remove;
        for (int i = 1; i <= n; i++) {
            if (a[i] % pw == 0 and a[i] % (2 * pw) != 0) {
                cur_ans++;
            } else {
                cur_remove.push_back(a[i]);
            }
        }
        if (cur_ans > largest) {
            largest = cur_ans;
            remove_best = cur_remove;
        }
        pw *= 2;
    }
    int ans = n - largest;
    cout << ans << "\n";
    for (int i: remove_best) {
        cout << i << " ";
    }
    cout << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/