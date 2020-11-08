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

const int maxn = 55;
int t;
int deg[maxn];
int res[maxn][maxn];

int query(vector<int> &v) {
    cout << "? ";
    cout << v.size() << " ";
    for (int i: v) {
        cout << i << " ";
    }
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

int query(int i) {
    vector<int> query_vec = {i};
    return query(query_vec);
}


int2 main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        deg[i] = query(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> query_vec = {i, j};
            int num_deg = query(query_vec);
            if (num_deg < deg[i] + deg[j]) {
                res[i][j] = res[j][i] = 1;
            }
        }
    }
    cout << "!" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/