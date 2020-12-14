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
#define inf 1e18

const int maxn = 1005;

vector<int> adj[maxn];
vector<int> res;
int visited[maxn];

void dfs(int u, int p) {
    visited[u] = 1;
    for (int v: adj[u]) {
        if (v != p) {
            if (!visited[v]) {
                dfs(v, u);
            }
        }
    }
    res.pb(u);
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string st;
        cin >> st;
        for (int j = 0; j < n; j++) {
            if (st[j] == '1') adj[i].pb(j);
            else if (st[j] == '0') adj[j].pb(i);
        }
    }

    dfs(0, 0);
    if ((int)res.size() < n) {
        cout << "impossible\n";
    } else {
        for (int elt: res) {
            cout << elt << " ";
        }
        cout << "\n";
    }


} 