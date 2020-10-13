#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int deg[maxn];
int ans = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        deg[u]++;
        deg[v]++;
        ans = max(ans, max(deg[u] + 1, deg[v] + 1));
    }
    cout << ans << "\n";
}