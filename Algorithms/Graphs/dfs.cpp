#include <bits/stdc++.h>

using namespace std;

void construct(vector<vector<int>> &adj, int m) {
    int n = adj.size() - 1;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
void dfs(vector<vector<int>> adj, int index, vector<int> &visited) {
    visited[0] = 1;
    visited[index] = 1;
    for(int num: adj[index]) {
        if(visited[num]) continue;
        visited[num] = 1;
        cout << num << "\n";
        dfs(adj, num, visited);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    construct(adj, m);
    vector<int> visited(n+1);
    cout << "1" << "\n";
    dfs(adj, 1, visited);

}
