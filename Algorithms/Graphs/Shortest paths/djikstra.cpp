#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
typedef priority_queue<pi> pqueue;

int INF = INT_MAX;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> distance(n+1);
    vector<vector<pi>> adj(n+1);
    vector<bool> processed(n+1);
    for(int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    for(int i = 1; i <= n; i++) distance[i] = INF;
    int x;
    cin >> x;
    pqueue q;
    distance[x] = 0;
    q.push({0, x});
    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if(processed[a]) continue;
        for(auto u: adj[a]) {
            int b = u.first, w = u.second;
            if(distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                q.push({-distance[b], b});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << distance[i] <<"\n";
    }

}