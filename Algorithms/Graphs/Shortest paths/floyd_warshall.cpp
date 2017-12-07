#include <bits/stdc++.h>

using namespace std;

int INF = INT_MAX/2;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>(n+1));
    vector<vector<int>> distance(n+1, vector<int>(n+1));

    for(int i = 1; i <= m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a][b] = d;
        adj[b][a] = d;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) distance[i][j] = 0;
            else if(adj[i][j]) distance[i][j] = adj[i][j];
            else distance[i][j] = INF;
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << distance[i][j] << " ";
        }
        cout << "\n";
    }
}