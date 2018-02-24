#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000;
vector<pair<int, int>> adj[MAXN];
int dist[MAXN];
bool processed[MAXN]; 
const int INF = INT_MAX >> 1;

int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    priority_queue< pair<int, int> > q;
    for(int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    int x;
    cin >> x;
    dist[x] = 0;
    q.push({0, x});
    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if(processed[a]) continue;
        processed[a] = true;
        for(auto u: adj[a]) {
            int b = u.first, w = u.second;
            if(dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dist[i] << "\n";
    }
}