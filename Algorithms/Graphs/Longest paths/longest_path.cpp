#include <bits/stdc++.h>

using namespace std;

int INF = INT_MAX - 1;

int findFurthest(int a, vector<vector<int>> adj, int n) {
    queue<int> q;
    vector<int> visited(n+1);
    q.push(a);
    int curr = a;
    while(!q.empty()) {
        curr = q.front(); q.pop();
        for(int i: adj[curr]) {
            if(visited[i]) continue;
            visited[i] = true;
            q.push(i);

        }
    }
    return curr;
}


int findLongest(int a, vector<vector<int>> adj, int n) {
    queue<int> q;
    vector<bool> visited(n+1);
    for(auto i: visited) cout << i << " ";
    cout << "\n";
    q.push(a);
    vector<int> distance(n+1);
    int maxDist = 0;
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for(int i: adj[curr]) {
            if(visited[i]) continue;
            visited[i] = true;
            distance[i] = distance[curr] + 1;
            maxDist = max(maxDist, distance[i]);
            q.push(i);
        }
    }
    for(auto i: visited) cout << i << " ";
    return maxDist;
}




int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    int tempA, tempB;
    cin >> tempA >> tempB;
    adj[tempA].push_back(tempB);
    adj[tempB].push_back(tempA);
    for(int i = 2; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int preAns = findFurthest(tempA, adj, n);
    int diameter = findLongest(preAns, adj, n);
    cout << preAns << "\n";
    cout << diameter << "\n";
}
