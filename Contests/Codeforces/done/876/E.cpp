// Contest 876, problem E

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
        if (pre[v] < pre[u]) { // back edge or tree edge
            if (!pre[v]) { // tree edge
                dfs(v, u);
                low[u] = min(low[u], low[v]);
            } else { // back edge
                low[u] = min(low[u], pre[v]);
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

// int limit = 1000;
bool print = false;
// int counter = 0;
// int rangesum = 0;
// int rangelimit = 50000;

void dfs2(int level, int l, int r) {
    // make sure empties are a (possibly nonempty) prefix of [l...r]
    if (!possible) return;

    for (int i = l + 1; i <= r; i++) {
        // something + empty = bad
        int sz0 = (int)words[i - 1].size();
        int sz1 = (int)words[i].size();
        if (sz0 > level and sz1 <= level) {
            possible = false;
            return;
        }
    }

    vector<int> nonempties;
    map<int, vector<int>> pos;
    // make sure there are no gaps
    
    for (int i = r; i >= l; i--) {
        if ((int)words[i].size() <= level) break;
        int cur_letter = words[i][level];
        if (!pos[cur_letter].empty() and pos[cur_letter].back() != i + 1) {
            possible = false;
            return;
        }
        pos[cur_letter].pb(i);
        // add satisfiability constraints
        if (i < r) {
            int cl = words[i][level];
            int cr = words[i + 1][level];
            if (cl < cr) {
                // ~cl v cr
                adj[cl + m].pb(cr + m);
                adj[cr].pb(cl);
                // cout << "cl: " << cl << ", cr: " << cr << "\n";
            } else if (cl > cr) {
                // (~cl v ~cl) ^ (cr v cr)
                adj[cl + m].pb(cl); // forces uppercase
                adj[cr].pb(cr + m); // forces lowercase
                // cout << cl << " uppercase, " << cr << " lowercase\n";
            }
        }
        if ((int)pos[cur_letter].size() == 2) {
            nonempties.pb(cur_letter);
        }
    }

    for (int elt: nonempties) {
        dfs2(level + 1, pos[elt].back(), pos[elt][0]);
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

    if (n == 20000 and m == 100000) {
        print = true;
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
    // for (int i = 1; i <= 2 * m; i++) {
    //     cout << "i: " << i << ", comp: " << comp[i] << "\n";
    // }
    form_compadj();

    // cout << comp[2] << " "<< comp[2 + m] << "\n";

    for (int i = 1; i <= m; i++) {
        if (comp[i] == comp[m + i]) {
            possible = false;
        }
    }
    if (!possible) {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        if (comp[i] < comp[i + m]) {
            ans.pb(i);
        }
    }
    cout << ans.size() << "\n";
    for (int elt: ans) {
        cout << elt << " ";
    }
    cout << "\n";

    
}