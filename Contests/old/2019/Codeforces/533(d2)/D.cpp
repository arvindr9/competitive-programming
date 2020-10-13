#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int speed[11];
int ans[11];
const int maxn = 1050;
char grid[maxn][maxn];
set<pair<int, int>> castles[11];
int n, m, p;
int expand = 0;

void explore(int player) {
    // cout << "hi " << remaining << "\n";
    queue<tuple<int, int, int>> cells;
    for (pair<int, int> pr: castles[player]) {
        cells.push(make_tuple(pr.first, pr.second, 0));
    }
    castles[player].clear();
    while (!cells.empty()) {
        int x, y, level;
        tie(x, y, level) = cells.front(); cells.pop();
        if (grid[x][y] == '.') {
            grid[x][y] = '0' + player;
            ans[player]++;
        }
        if (level + 1 > speed[player]) {castles[player].insert({x, y});  continue;}
        if (grid[x + 1][y] == '.') {
            cells.push(make_tuple(x + 1, y, level + 1));
            expand = 1;
        }
        if (grid[x - 1][y] == '.') {
            cells.push(make_tuple(x - 1, y, level + 1));
            expand = 1;
        }
        if (grid[x][y + 1] == '.') {
            cells.push(make_tuple(x, y + 1, level + 1));
            expand = 1;
        }
        if (grid[x][y - 1] == '.') {
            cells.push(make_tuple(x, y - 1, level + 1));
            expand = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) {
        cin >> speed[i];
    }
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= m; j++) {
            char cell = s[j - 1];
            grid[i][j] = cell;
            if (isdigit(cell)) {
                ans[cell - '0']++;
                castles[cell - '0'].insert({i, j});
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int i = 0;
    while (true) {
        expand = 0;
        for (int i = 1; i <= p; i++) {
            explore(i);
        }
        if (expand == 0) break;
    }
    for (int i = 1; i < p; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[p] << "\n";
}