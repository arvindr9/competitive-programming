// 1408 G

// based on ecnerwala's solution

#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define f first
#define s second

const int mod = 998244353;

int reduce(int a) {
    return (a %= mod) < 0 ? a + mod : a;
}
int add(int a, int b) {
    return reduce(a + b);
}

int prod(int a, int b) {
    return reduce(a * b);
}

const int maxn = 1505;

int par[maxn], sz[maxn], numE[maxn];
vector<int> dp[maxn];

int find(int u) {
    return (u == par[u]) ? u : find(par[u]);
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, pi>> edges;
    for (int i = 1;i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if (i == j) {
                assert(a == 0);
                continue;
            }
            if (i < j) {
                edges.pb({a, mp(i, j)});
            }
        }
    }
    sort(edges.begin(), edges.end());
    vector<vector<int>> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = {0, 1};
    }
    for (int i = 1; i <= n; i++) sz[i] = 1, par[i] = i;

    for (auto &[w, p]: edges) {
        auto &[u, v] = p;
        u = find(u), v = find(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            vector<int> &dp1 = dp[u], &dp2 = dp[v];
            vector<int> next_dp((int)dp1.size() + (int)dp2.size() - 1);
            for (int i = 1; i < dp1.size(); i++) {
                for (int j = 1; j < dp2.size(); j++) {
                    next_dp[i + j] = add(next_dp[i + j], prod(dp1[i], dp2[j]));
                }
            }
            dp[u] = std::move(next_dp);
            dp[v] = {};
            sz[u] += sz[v];
            par[v] = u;
            numE[u] += numE[v];
        }
        numE[u]++;
        assert((int)dp[u].size() == sz[u] + 1);
        if (numE[u] == sz[u] * (sz[u] - 1) / 2) dp[u][1] = add(dp[u][1], 1);
    }
    int r = find(1); 
    assert((int)dp[r].size() == n + 1);
    for (int i = 1; i <= n; i++) {
        cout << dp[r][i] << " ";
    }
    cout << "\n";
}