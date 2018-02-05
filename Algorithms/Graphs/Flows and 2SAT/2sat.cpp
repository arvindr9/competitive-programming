#include <bits/stdc++.h>

using namespace std;

#define SHOW(a) std::cout << #a << ": \n"

int maxn = 2000;
stack<int> s;
int counter = 0;
vector<int> marked(2 * maxn + 2);
vector<int> component(2 * maxn + 2);
vector<vector<int>> adj(2 * maxn + 2);
vector<vector<int>> adj2(2 * maxn + 2);
vector<pair<int, int>> edges;

vector<int> clearVec(vector<int> &v) {
    vector<int> ret(2 * maxn + 2);
    return ret;
}

int string_to_node(string s) {
    if(s[0] == '~') {
        return (2 * (s[1] - 'a') + 1);
    }
    return 2 * (s[0] - 'a');
}

int find_not(int node) {
    return (node ^ 1);
}

void dfsFirst(int v) {
    marked[v] = true;
    for(int u: adj[v]) {
        if(!marked[u]) {
            dfsFirst(u);
        }
    }
    s.push(v);
}

void dfsSecond(int v) {
    marked[v] = true;
    for(int u: adj2[v]) {
        if(!marked[u]) {
            dfsSecond(u);
        }
    }
    component[v] = counter;
}


int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        string s1, s2; cin >> s1 >> s2;
        int a = string_to_node(s1), b = string_to_node(s2);
        adj[find_not(a)].push_back(b); //~x, y
        adj[find_not(b)].push_back(a); //~y, x
        edges.push_back({a, b});
    }

    for(int i = 0; i < m; i += 1) {
        int x = edges[i].first, y = edges[i].second;
        if(!marked[x]) {
            dfsFirst(x);
        }
        if(!marked[y]) {
            dfsFirst(y);
        }
        if(!marked[find_not(x)]) {
            dfsFirst(find_not(x));
        }
        if(!marked[find_not(y)]) {
            dfsFirst(find_not(y));
        }
    }
    marked = clearVec(marked);

    for(auto e: edges) {
        swap(e.first, e.second);
    }

    for(int i = 0; i < 2 * n + 1; i++) {
        for(int j: adj[i]) {
            adj2[j].push_back(i);
        }
    }

    while (!s.empty()) {
        int v = s.top(); s.pop();
        if(!marked[v]) {
            counter++;
            dfsSecond(v);
        }
    }
    
    for(int i = 0; i < m; i++) {
        int x = edges[i].first, y = edges[i].second;
        if(component[x] == component[find_not(x)] || component[y] == component[find_not(y)]) {
            cout << "unsatisfiable\n";
            return 0;
        }
    }
    cout << "satisfiable\n";

}