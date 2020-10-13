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
    string st;
    cin >> st;
    int n = st.size();
    vector<pair<char, int>> vec; //char, original index
    vector<int> less(n);
    int min_taken = n;
    vector<pair<int, string>> ans;
    for (int i = n - 1; i >= 0; i--) {
        vec.pb({st[i], i});
        int vec_size = vec.size();
        while (vec_size >= 2) {
            auto p1 = vec[vec_size - 1];
            auto p2 = vec[vec_size - 2];
            char c1 = p1.f;
            char c2 = p2.f;
            int i1 = p1.s;
            int i2 = p2.s;
            if (c1 == c2) {
                less[i1] = less[i2];
            }
            if (c1 < c2) {
                less[i1] = 1;
            }
            if (!less[i1] and c1 == c2) {
                if (i1 < min_taken and i2 < min_taken) {
                    vec.pop_back();
                    vec.pop_back();
                    min_taken = min(i1, i2);
                } else {
                    break;
                }
            } else {
                break;
            }
            vec_size = vec.size();
        }
        vec_size = vec.size();
        string res = "";
        if (vec_size > 10) {
            for (int j = 1; j <= 5; j++) {
                res += vec[vec_size - j].f;
            }
            res += "...";
            for (int j = 1; j >= 0; j--) {
                res += vec[j].f;
            }
        } else {
            for (int j = vec_size - 1; j >= 0; j--) {
                res += vec[j].f;
            }
        }
        ans.pb(mp(vec_size, res));
    }
    for (int i = n - 1; i >= 0; i--) {
        cout << ans[i].f << " " << ans[i].s << "\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/