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

const int maxb = 30;
vector<vector<int> > process[maxb + 1];

pi test(int b) {
    int num_process = process[b].size();
    int inv1 = 0; // inversions that result from toggling
    int inv0 = 0;
    //test digit = 1
    for (int i = 0; i < num_process; i++) {
        vector<int> vec = process[b][i];
        int num0 = 0;
        int num1 = 0;
        int num_elts = vec.size();
        for (int i = 0; i < num_elts; i++) {
            int elt = vec[i];
            if (elt & (1 << b)) {
                inv1 += num0;
                num1++;
            } else {
                inv0 += num1;
                num0++;
            }
        }
    }
    pi p1 = mp(inv1, 1);
    pi p0 = mp(inv0, 0);

    return min(p1, p0);
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> initial(n);
    for (int i = 0; i < n; i++) {
        cin >> initial[i];
    }
    int total_inv = 0;
    int k = 0;
    process[maxb].pb(initial);
    for (int b = maxb; b >= 0; b--) {
        pi inv_k = test(b);
        // pi inv_k = mp(0, 0);
        while (!process[b].empty()) {
            // update next stuff
            vector<int> vec = process[b].back();
            vector<int> vec0;
            vector<int> vec1;
            for (int elt: vec) {
                if ((1 << b) & elt) {
                    vec1.pb(elt);
                } else {
                    vec0.pb(elt);
                }
            }
            if (b > 0) {
                if (!vec1.empty()) {
                    process[b - 1].pb(vec1);
                }
                if (!vec0.empty()) {
                    process[b - 1].pb(vec0);
                }
            }
            process[b].pop_back();
        }
        total_inv += inv_k.f;
        k |= (inv_k.s << b);
    }
    cout << total_inv << " " << k << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/