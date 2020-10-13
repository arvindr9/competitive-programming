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
string st;
int n, k;


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> st;
        int total_score = 0;
        int numL = 0;
        vector<int> w_indices;
        if (st[0] == 'W') total_score++;
        else numL++;
        for (int i = 1; i < n; i++) {
            if (st[i] == 'W') {
                if (st[i - 1] == 'W') total_score += 2;
                else total_score++;
            } else {
                numL++;
            }
        }
        if (k > 0) {
            if (numL == n) {
                numL--;
                k--;
                total_score++;
                st[0] = 'W';
            }
        }

        vector<int> mid_gaps; //gives length of gaps in middle
        vector<int> endpts;
        if (st[0] == 'L') {
            for (int i = 0; i < n; i++) {
                if (st[i] == 'W') {
                    endpts.pb(i);
                    break;
                }
            }
        }
        if (st[n - 1] == 'L') {
            for (int i = n - 1; i >= 0; i--) {
                if (st[i] == 'W') {
                    endpts.pb(n - i - 1);
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (st[i] == 'W') w_indices.push_back(i);
        }
        int num_ind = w_indices.size();
        for (int i = 1; i < num_ind; i++) {
            if (w_indices[i] > w_indices[i - 1] + 1) {
                mid_gaps.push_back(w_indices[i] - w_indices[i - 1] - 1);
            }
        }
        sort(all(mid_gaps));

        // cout << "pre total score: " << total_score << "\n";
        for (int gap: mid_gaps) {
            // cout << "mid gap size: " << gap << "\n";
            if (gap <= k) {
                k -= gap;
                total_score += 2 * gap + 1;
            } else {
                total_score += 2 * k;
                k = 0;
                break;
            }
        }
        for (int gap: endpts) {
            // cout << "end gap size: " << gap << "\n";
            if (gap <= k) {
                k -= gap;
                total_score += 2 * gap;
            } else {
                total_score += 2 * k;
                k = 0;
                break;
            }
        }
        cout << total_score << "\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/