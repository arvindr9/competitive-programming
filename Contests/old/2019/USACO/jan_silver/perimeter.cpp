#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

const ll maxn = 1050;
ll N;

char grid[maxn][maxn];
ll visited[maxn][maxn];
ll perimeter[maxn];
ll area[maxn];
ll curComp = 1;
ll visitedComp = 0;

void dfs(ll i, ll j) {
    if (i <= 0 || i > N || j <= 0 || j > N || visited[i][j]) return;
    visited[i][j] = 1;
    if (grid[i][j] == '.') return;
    visitedComp = 1; //the square is a #
    area[curComp]++;
    if (i == 1) perimeter[curComp]++;
    if (i == N) perimeter[curComp]++;
    if (j == 1) perimeter[curComp]++;
    if (j == N) perimeter[curComp]++;
    if (i > 1 && grid[i - 1][j] == '.') perimeter[curComp]++;
    if (j > 1 && grid[i][j - 1] == '.') perimeter[curComp]++;
    if (i < N && grid[i + 1][j] == '.') perimeter[curComp]++;
    if (j < N && grid[i][j + 1] == '.') perimeter[curComp]++;
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin >> N;
    for (ll i = 1; i <= N; i++) {
        string s; cin >> s;
        for (ll j = 1; j <= N; j++) {
            grid[i][j] = s[j - 1];
        }
    }
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            visitedComp = 0;
            dfs(i, j);
            if (visitedComp) {
                curComp++;}
        }
    }
    ll mxArea = 0;
    ll mnPerim = 1e9;

    for (ll comp = 1; comp < curComp; comp++) {
        mxArea = max(mxArea, area[comp]);
    }
    for (ll comp = 1; comp < curComp; comp++) {
        if (area[comp] == mxArea) mnPerim = min(mnPerim, perimeter[comp]);
    }
    if (mnPerim == (ll)1e9) mnPerim = 0;
    cout << mxArea << " " << mnPerim << "\n";
}