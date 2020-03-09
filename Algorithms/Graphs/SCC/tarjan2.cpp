// A version that I might like better (because of the namings of the variables). My incorrect solution to SWERC 2020 K:

const int maxn = 1e5 + 5;

vector<int> adj[maxn];
int dfn[maxn], low[maxn], belong[maxn];
int source[maxn], instack[maxn];
int cnt = 0, num = 0;
stack<int> s;

void tarjan(int u) {
    instack[u] = true;
    dfn[u] = low[u] = ++cnt;
    s.push(u);
    for (int v: adj[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (instack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        source[++num] = true;
        while (1) {
            int p = s.top();
            s.pop();
            instack[p] = false;
            belong[p] = num;
            if (p == u) break;
        }
    }
}
vector<int> ans;
int n, m, t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        if (!dfn[i]) tarjan(i);
    }

    for (int i = 0; i < n; i++) {
        for (int u: adj[i]) {
            if (u == t && belong[u] != belong[i]) {
                ans.push_back(i);
            }
        }
    }
    cout << ans.size() << "\n";
    for (int u: ans) {
        cout << u << "\n";
    }
}
