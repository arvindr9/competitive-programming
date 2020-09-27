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
        map<int, vector<int> > occurrences;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            occurrences[a[i]].push_back(i);
        }
        map<int, int> max_sep;
        for (auto e: occurrences) {
            int elt = e.first;
            vector<int> indices = e.second;
            int num_ind = indices.size();
            max_sep[elt] = indices[0] - 0;
            max_sep[elt] = max(max_sep[elt], n + 1 - indices[num_ind - 1]);
            for (int i = 1; i < num_ind; i++) {
                max_sep[elt] = max(max_sep[elt], indices[i] - indices[i - 1]);
            }
        }
        map<int, vector<int> > sep_to_elts;
        for (auto e: max_sep) {
            sep_to_elts[e.s].push_back(e.f);
        }
        map<int, int> sep_to_min;
        int cur_min = 1e9 + 1;
        for (auto &e: sep_to_elts) {
            sort(all(e.s));
            cur_min = min(cur_min, e.s[0]);
            sep_to_min[e.f] = cur_min;
        }
        vector<int> ans;
        for (int k = 1; k <= n; k++) {
            auto it = sep_to_min.upper_bound(k);
            if (it != sep_to_min.begin()) {
                it--;
                ans.push_back(it->s);
            } else {
                ans.push_back(-1);
            }
        }
        for (int k = 1; k <= n; k++) {
            cout << ans[k - 1] << " ";
        }
        cout << "\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/