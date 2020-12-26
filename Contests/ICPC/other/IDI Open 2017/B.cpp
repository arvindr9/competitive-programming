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

int numv = 0;

int mincost(int startv, int endv, vector<vector<int>> &adj) {
    vector<int> dist(numv + 1);
    vector<int> visited(numv + 1);
    fill(dist.begin(), dist.end(), inf);
    visited[startv] = 1;
    dist[startv] = 0;
    queue<int> q;
    q.push(startv);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: adj[u]) {
            if (visited[v]) continue;
            visited[v] = 1;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return dist[endv];
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> dadj(maxn), eadj(maxn);

    int a, f, n, m;
    cin >> a >> f >> n >> m;

    int startv;
    int goalv;
    vector<pi> coords(maxn);

    for (int i = 0; i < n; i++) {
        string st;
        cin >> st;
        for (int j = 0; j < m; j++) {
            if (st[j] != 'B') {
                numv++;
                coords[numv] = {i, j};
                if (st[j] == 'S') startv = numv;
                else if (st[j] == 'G') goalv = numv;
            }
        }
    }

    auto dist2 = [&](pi p1, pi p2) {
        int dx = (p2.f - p1.f);
        int dy = (p2.s - p1.s);
        return dx * dx + dy * dy;
    };

    auto manh = [&](pi p1, pi p2) {
        return abs(p1.f - p2.f) + abs(p1.s - p2.s);
    };

    auto line = [&](pi p1, pi p2) {
        return p1.f == p2.f or p1.s == p2.s;
    };

    for (int i = 1; i <= numv; i++) {
        for (int j = i + 1; j <= numv; j++) {
            if (dist2(coords[i], coords[j]) <= a * a) {
                eadj[i].pb(j);
                eadj[j].pb(i);
            }
            if (line(coords[i], coords[j]) and manh(coords[i], coords[j]) <= f) {
                dadj[i].pb(j);
                dadj[j].pb(i);
            }
        }
    }


    int dd = mincost(startv, goalv, dadj);
    int ed = mincost(startv, goalv, eadj);


    if (dd == inf and ed == inf) {
        cout << "NO WAY\n";
        return 0;
    }
    if (dd > ed) {
        cout << "GO FOR IT\n";
    } else if (dd == ed) {
        cout << "SUCCESS\n";
    } else {
        cout << "NO CHANCE\n";
    }




}   