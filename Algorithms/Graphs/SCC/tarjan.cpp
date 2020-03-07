#include <bits/stdc++.h>

// Source: Jiahui Lu

using namespace std;
int cnt = 0, num = 0;
vector<int> e[5010];
bool instack[5010], source[5010];
stack<int> s;
int dfn[5010], low[5010], belong[5010];

void tarjan(int x) {
	instack[x] = true;
	dfn[x] = low[x] = ++cnt;
	s.push(x);
	for (int y : e[x]) {
		if (!dfn[y]) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if (instack[y]) low[x] = min(low[x], dfn[y]); // seems equal to low[x] = min(low[x], low[y])
	}
	if (low[x] == dfn[x]) {
		source[++num] = true;
		while (1) {
			int p = s.top();
			s.pop();
			instack[p] = false;
			belong[p] = num;
			if (p == x) break;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	int n,m,s; cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int x,y; cin >> x >> y;
		e[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++) 
		for (int y : e[i]) if (belong[y] != belong[i]) source[belong[y]] = false;
	int ans = 0;
	for (int i = 1; i <= num; i++) if (source[i]) ans++;
	cout << ans - (source[belong[s]]) << "\n";
}
