// TODO: fix and finish this

#include <bits/stdc++.h>
using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second;
#define inf 1e18

const int maxn = 2e5 + 5;

vector<int> adj[maxn], compadj[maxn];
int low[maxn], pre[maxn], comp[maxn];
int timer = 0;
int comptimer = 0;
vector<int> stk;

int n, m;

void dfs(int u, int p) {
    pre[u] = low[u] = ++timer;
    stk.pb(u);
    for (int v: adj[u]) {
        if (v != p) {
            if (pre[v] < pre[u]) { // back edge or tree edge
                if (!pre[v]) { // tree edge
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                } else { // back edge
                    low[u] = min(low[u], pre[v]);
                }
            }
        }
    }
    if (pre[u] == low[u]) {
        // process component
        comptimer++;
        while (stk.back() != u) {
            int v = stk.back();
            comp[v] = comptimer;
            stk.pop_back();
        }
        comp[u] = comptimer;
        stk.pop_back();
    }
    pre[u] = inf;
}

void form_compadj() {
    for (int u = 1; u <= 2 * m; u++) {
        for (int v: adj[u]) {
            if (comp[u] != comp[v]) {
                compadj[comp[u]].pb(comp[v]);
            }
        }
    }
    for (int i = 1; i <= comptimer; i++) {
        vector<int> & edges = compadj[i];
        sort(edges.begin(), edges.end());
        compadj[i].erase(unique(edges.begin(), edges.end()), edges.end());
    }
}

vector<int> words[maxn];

bool possible = true;

void dfs(int level, int l, int r) {
    // make sure empties are a (possibly nonempty) prefix of [l...r]
    vector<int> empties;
    for (int i = l; i <= r; i++) {
        if ((int)words[i].size() >= level) {
            empties.pb(i);
            if (empties[0] != l) {
                possible = false;
                return;
            }
            int num_empties = empties.size();
            if (num_empties >= 2 and empties[num_empties - 2] != empties.back() - 1) {
                possible = false;
                return;
            }
        }
    }
    vector<int> pos(m + 1);
    // make sure there are no gaps
    for (int i = r; i >= l; i--) {
        if ((int)words.size() >= level) break;
        int cur_letter = words[i][level];
        if (!pos[cur_letter].empty() and pos[cur_letter].back() != i + 1) {
            possible = false;
            return;
        }
        pos[cur_letter].pb(j);
        for (int i = 1; i < cur_letter; i++) {
            if (!pos[i].empty()) {
                // !curletter and i must be true (i.e. adding a constraint)
                adj[curletter].pb(m + i);
                adj[m + i].pb(curletter + i);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (!pos[i].empty()) {
            dfs(level + 1, pos[i][0], pos[i].back());
        }
    } 
}

void clean_adj() {
    for (int i = 1; i <= 2 * m; i++) {
        vector<int> &edges = adj[i];
        sort(edges.begin(), edges.end());
        edges.erase(unique(edges.begin(), edges.end()), edges.end());
    }
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        for (int j = 1; j <= l; j++) {
            int a;
            cin >> a;
            words[i].pb(a);
        }
    }

    dfs2(0, 1, n);
    if (!possible) {
        cout << "No\n";
        return 0;
    }

    clean_adj();

    for (int u = 1; u <= 2 * m; u++) {
        if (!pre[u]) dfs(u, u);
    }
    form_compadj();

    for (int i = 1; i <= m; i++) {
        if (comp[i] == comp[m + i]) {
            possible = false;
        }
    }
    if (!possible) {
        cout << "No\n";
        return 0;
    }

    
}