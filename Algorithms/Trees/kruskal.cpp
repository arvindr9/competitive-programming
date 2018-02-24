//Kruskal's Algorithm
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20000;
int link[MAXN], size[MAXN];
int n, m;

set<pair<int, pair<int, int>>> s;

int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}

int same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(size[a] < size[b]) {
        swap(a, b);
    }
    size[a] += size[b];
    link[b] = a;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        link[i] = i;
        size[i] = 1;
    }
    for(int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        s.insert({w, {a, b}});
    }
    int ans = 0;
    while((int)s.size() > 0) {
        auto x = *(s.begin());
        int w = s.begin()->first;
        pair<int, int> edge = s.begin() -> second;
        int a = edge.first, b = edge.second;
        if(!same(a, b)) {
            unite(a, b);
            ans += w;
        }
        s.erase(x);
    }
    cout << ans << "\n";
}

