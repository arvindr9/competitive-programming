#include <bits/stdc++.h>

using namespace std;

int INF = INT_MAX;

int main() {
    int n;
    cin >> n;
    int numE;
    cin >> numE;
    vector<int> distance(n+1);
    vector<tuple<int, int, int>> edges;
    for(int i = 1; i <= n; i++) distance[i] = INF;
    for (int i = 1; i <= numE; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back(make_tuple(a, b, w));}
    int x;
    cin >> x;
    distance[x] = 0;
    for(int i = 1; i <= n-1; i++) {
        int a, b, w;
        for (auto e: edges) {
            tie(a, b, w) = e;
            distance[b] = min(distance[b], distance[a] + w);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << distance[i] << "\n";
    }
}
