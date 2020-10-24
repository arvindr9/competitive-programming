#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

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
// const int INF = 1 << 26;
const int MX = 100001;

const int maxn = 2e5 + 5;
int t;

// based on kostia244's solution


struct node {
    int cost[5][5];

    node() { for (int i = 0; i < 25; i++) cost[i/5][i%5] = INF;}
    node(char c) {
        for (int i = 0; i < 25; i++) {
            cost[i / 5][i % 5] = INF * ((i / 5) != (i % 5));
        }
        if(c == '2') {
			cost[0][0] = 1;
			cost[0][1] = 0;
		}
		if(c == '0') {
			cost[1][1] = 1;
			cost[1][2] = 0;
		}
		if(c == '1') {
			cost[2][2] = 1;
			cost[2][3] = 0;
		}
		if(c == '7') {
			cost[3][3] = 1;
			cost[3][4] = 0;
		}
		if(c == '6') {
			cost[3][3] = 1;
			cost[4][4] = 1;
		}

    }
    friend node operator+(const node&a, const node&b) {
        node c;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    c.cost[i][j] = min(c.cost[i][j], a.cost[i][k] + b.cost[k][j]);
                }
            }
        }
        return c;
    }
};


node tree[2 * maxn];
int n, m;
string st;

int get(int l, int r) {
    node resl('9'), resr('9');
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l&1) resl = resl + tree[l++];
        if (r&1) resr = tree[--r] + resr;
    }
    resl = resl + resr;
    return resl.cost[0][4];
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> n >> m >> st;
    for (int i = 0; i < n; i++) {
        tree[n + i] = node(st[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = get(l, r);
        if (ans > n) ans = -1;
        cout << ans << "\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/