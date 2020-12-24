#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second

#define INF 1e18

const int maxn = 1e5 + 5;
int t[4 * maxn];

int query_min(int v, int tl, int tr, int l, int r) {
    if (l > r) return INF;
    if (l == tl and r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(query_min(2 * v, tl, tm, l, min(tm, r)), query_min(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        update(2 * v, tl, tm, pos, val);
    } else {
        update(2 * v + 1, tm + 1, tr, pos, val);
    }
    t[v] = min(t[2 * v], t[2 * v + 1]);
}


int n;
int a[maxn];

int query_min(int l, int r) {
    return query_min(1, 1, n, l, r);
}

void update(int pos, int val) {
    update(1, 1, n, pos, val);
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<pair<pi, int>> queries; // {{l, r}, mex}
    vector<vector<int>> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].pb(i);
    }
    for (int i = 1; i <= n; i++) {
        if (pos[i].empty()) {
            queries.pb(mp(mp(1, n), i));
        } else {
            int num_elts = pos[i].size();
            if (pos[i][0] > 1) {
                queries.pb(mp(mp(1, pos[i][0] - 1), i));
            }
            if (pos[i].back() < n) {
                queries.pb(mp(mp(pos[i].back() + 1, n), i));
            }
            for (int j = 1; j < num_elts; j++) {
                if (pos[i][j] > pos[i][j - 1] + 1) {
                    queries.pb(mp(mp(pos[i][j - 1] + 1, pos[i][j] - 1), i));
                }
            }
        }
    }
    queries.pb(mp(mp(1, n), n + 1));
    sort(queries.begin(), queries.end(), [&] (auto a1, auto a2) {return a1.f.s < a2.f.s;}); //sorting by right coordinate
    int num_queries = queries.size();
    for (int i = 1; i <= n; i++) {
        update(i, -1);
    }

    set<int> mexes;

    for (int rbound = 1, cur_query = 0; rbound <= n and cur_query < num_queries; rbound++) {
        update(a[rbound], rbound);
        while (cur_query < num_queries and queries[cur_query].f.s == rbound) {
            pair<pi, int> query = queries[cur_query];
            int l = query.f.f;
            int r = query.f.s;
            int target_mex = query.s;
            int earliest_index = query_min(1, target_mex - 1);
            if (earliest_index >= l) {
                mexes.insert(target_mex);
            }
            cur_query++;
        }
    }

    for (int i = 1; i <= n + 2; i++) {
        if (!mexes.count(i)) {
            cout << i << "\n";
            break;
        }
    }
}