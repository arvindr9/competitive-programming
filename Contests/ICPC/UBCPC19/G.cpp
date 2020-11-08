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

const int maxn = 1e7 + 5;
int t;
int isprime[maxn];

int down[10][10], rig[10][10];
int arr[10][10];

int n, m;


int ans = 0;

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


void dfs(int i, int j) {
    int above = down[i - 1][j];
    int left = rig[i][j - 1];
    for (int a = 1; a <= 9; a++) {
        if (isprime[10 * above + a] and isprime[10 * left + a]) {
            arr[i][j] = a;
            if (i == n and j == m) {
                // print();
                ans++;
                // cout << "bottom row: " << 10 * left + a << "\n";
                // cout << "top row: " << 10 * above + a << "\n";
                continue;
            }
            down[i][j] = 10 * above + a;
            rig[i][j] = 10 * left + a;
            if (j == m) {
                dfs(i + 1, 1);
            } else {
                dfs(i, j + 1);
            }
        }
    }
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    for (int i = 2; i < maxn; i++) {
        isprime[i] = 1;
    }
    for (int i = 2; i < maxn; i++) {
        if (isprime[i]) {
            for (int j = 2 * i; j < maxn; j += i) {
                isprime[j] = 0;
            }
        }
    }
    cin >> n >> m;

    dfs(1, 1);
    cout << ans << "\n";

    // find_primes(0, 1);
    // for (int i = 1; i <= 8; i++) {
    //     cout << freq[i] << "\n";
    // }

    // cin >> n >> m;

    // dfs(1, 1);

    // cin >> t;
    // while (t--) {
        
    // }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/