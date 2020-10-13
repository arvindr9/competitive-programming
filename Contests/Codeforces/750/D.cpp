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
const int mod = 1e9 + 7;

const int maxn = 305;
int visited[maxn][maxn];
int last_visit[maxn][maxn][8];
int visited2[maxn][maxn][8][6];
int t[31];

int n;

//start pos = 300, 300

map<string, vector<string>> nxt = {
    {"nw", {"n", "w"}},
    {"ne", {"n", "e"}},
    {"sw", {"s", "w"}},
    {"se", {"s", "e"}},
    {"n", {"nw", "ne"}},
    {"w", {"nw", "sw"}},
    {"e", {"se", "ne"}},
    {"s", {"sw", "se"}}
};

map<string, pi> dirs = {
    {"nw", {-1, -1}},
    {"ne", {-1, 1}},
    {"sw", {1, -1}},
    {"se", {1, 1}},
    {"n", {-1, 0}},
    {"w", {0, -1}},
    {"e", {0, 1}},
    {"s", {1, 0}}
};

map<string, int> idx = {
    {"nw", 0},
    {"ne", 1},
    {"sw", 2},
    {"se", 3},
    {"n", 4},
    {"w", 5},
    {"e", 6},
    {"s", 7}
};

void dfs(int i, int j, int iter, string dir) {

    if (iter > n) return;
    int dir_index = idx[dir];
    if (last_visit[i][j][dir_index] == iter) return;
    int dist = t[iter];
    pi to = dirs[dir];
    last_visit[i][j][dir_index] = iter;
    if (!visited2[i][j][dir_index][dist]) {
        
        visited[i][j] = 1;

        int i2 = i;
        int j2 = j;
        for (int ii = 0; ii < dist; ii++) {
            i2 = i + ii * to.f;
            j2 = j + ii * to.s;
            visited[i2][j2] = 1;
        }
        visited2[i][j][dir_index][dist] = 1;
    }
    int i2 = i + (dist - 1) * to.f;
    int j2 = j + (dist - 1) * to.s;


    // cout << "i2: " << i2 << ", j2: " << j2 << "\n";
    for (string st: nxt[dir]) {
        int nexti = i2 + dirs[st].f;
        int nextj = j2 + dirs[st].s;
        dfs(nexti, nextj, iter + 1, st);
    }
}



int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    dfs(150, 150, 1, "n");
    int ans = 0;
    for (int i = 0; i <= 300; i++) {
        for (int j = 0; j <= 300; j++) {
            ans += visited[i][j];
        }
    }
    cout << ans << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/