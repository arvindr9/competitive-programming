#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
const int inf = 1e18;

int t;
const int maxn = 2e5 + 5;
vector<pi> adj[maxn];
int sub[maxn];
int B = 0;

int n;

void reset() {
    for (int i = 1; i <= 2 * n; i++) {
        adj[i].clear();
        sub[i] = 0;
        B = 0;
    }
}

int dfs0(int u, int p) {
    sub[u] = 1;
    for (auto &[v, w]: adj[u]) {
        if (v != p) {
            sub[u] += dfs0(v, u);
        }
    }
    return sub[u];
}

int dfs1(int u, int p, int taken) {
    int res = 0;
    int numc = 0;
    vector<pi> odds;
    vector<pi> evens;
    for (auto &[v, w]: adj[u]) {
        if (v != p) {
            if (sub[v] % 2 == 1) {
                res += w + dfs1(v, u, 1);
            } else {
                res += dfs1(v, u, 0);
            }
        }
    }
    // sort(odds.begin(), odds.end());
    return res;
}

void dfs2(int u, int p) {
    for (auto &[v, w]: adj[u]) {
        if (v != p) {
            B += w * min(sub[v], 2 * n - sub[v]);
            dfs2(v, u);
        }
    }
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        reset();
        for (int i = 1; i < 2 * n; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            adj[u].eb(v, d);
            adj[v].eb(u, d);
        }
        dfs0(1, 1);
        int G = dfs1(1, 1, 0);
        // cout << "G: " << G << "\n";
        dfs2(1, 1);
        // cout << "B: " << B << "\n";
        cout << G << " " << B << "\n";
    }
} 