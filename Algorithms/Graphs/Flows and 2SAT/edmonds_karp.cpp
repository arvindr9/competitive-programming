/**
 * Finds the maximum flow using Edmonds-Karp. Time complexity: O(EV^2)
 * Author: arvindr9
 **/
#include <bits/stdc++.h>

using namespace std;
const int maxn = 150;
const int maxm = 10050;

vector<int> adj[maxn];
map<pair<int, int>, int> res;

int n, m;

int main() {
    freopen("evacuation.in", "r", stdin);
    freopen("evacuation.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(v);
        res[{u, v}] = c;
    }

    bool done = false;
    int ans = 0;
    while (!done) {
        queue<int> q;
        q.push(1);
        vector<int> prev(n + 1);
        vector<int> visited(n + 1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v: adj[u]) {
                if (!visited[v] && res[{u, v}] != 0) {
                    visited[v] = 1;
                    prev[v] = u;
                    q.push(v);
                }
            }
        }
        if (visited[n]) {
            int n2 = n;
            int mn = 20000;
            while (prev[n2] != 0) {
                mn = min(mn, res[{prev[n2], n2}]);
                n2 = prev[n2];
            }
            n2 = n;
            while (prev[n2] != 0) {
                res[{prev[n2], n2}] -= mn;
                res[{n2, prev[n2]}] += mn;
                n2 = prev[n2];
            }
            n2 = n;
            cout << n;
            while (prev[n2] != 0) {
                cout << " " << prev[n2];
                n2 = prev[n2];
            }
            cout << "\n";
            ans += mn;
        }
        if (!visited[n]) {
            done = true;
        }
    }
    cout << ans << "\n";
}