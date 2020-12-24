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

string printed(int mask) {
    string res;
    for (int i = 0; i < 26; i++) {
        if (mask & (1 << i)) {
            res += '1';
        } else {
            res += '0';
        }
    }
    return res;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    string st;
    cin >> st;

    vector<int> elts_prev(n);
    vector<int> mapping(26);
    vector<int> backmap(26);
    vector<int> elts(n);
    fill(mapping.begin(), mapping.end(), -1);
    int curmap = 0;
    for (int i = 0; i < n; i++) {
        elts_prev[i] = st[i] - 'a';
        if (mapping[elts_prev[i]] == -1) {
            mapping[elts_prev[i]] = curmap;
            backmap[curmap] = elts_prev[i];
            curmap++;
        }
    }
    for (int i = 0; i < n; i++) {
        elts[i] = mapping[elts_prev[i]];
    }
    vector<int> l(curmap), r(curmap), freq(curmap);
    fill(l.begin(), l.end(), INF);
    fill(r.begin(), r.end(), -INF);
    for (int i = 0; i < n; i++) {
        l[elts[i]] = min(l[elts[i]], i);
        r[elts[i]] = max(r[elts[i]], i);
        freq[elts[i]]++;
    }

    int maxn = 1 << curmap;

    vector<bool> satisfy(maxn);
    vector<int> dp(maxn);
    fill(dp.begin(), dp.end(), -1);

    dp[0] = 1;

    function<int(int)> solve = [&](int i) {
        if (~dp[i]) return dp[i];
        dp[i] = 0;
        int ll = INF, rr = -INF;
        int amt = 0;
        vector<int> elts;
        for (int j = 0; j < curmap; j++) {
            if (i & (1 << j)) {
                rr = max(rr, r[j]);
                ll = min(ll, l[j]);
                amt += freq[j];
                elts.pb(j);
            }
        }

        bool can_change = (amt >= ((a * (rr - ll + 1) + (b - 1)) / b));

        // Case 1: change all elements to color j
        if (can_change) {
            for (int j: elts) {
                dp[i] |= solve(i ^ (1 << j));
            }
        }

        // Case 2: multiple subtrees
        int cur_mask = 0;
        for (int j: elts) {
            cur_mask |= (1 << j);
            if (cur_mask == i) break;
            dp[i] |= (solve(cur_mask) & solve(i ^ cur_mask));
        }
        return dp[i];
    };

    vector<int> ans;
    for (int i = 0; i < curmap; i++) {
        if (solve((maxn - 1) ^ (1 << i)) == 1) {
            ans.pb(backmap[i]);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << " ";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << (char)('a' + ans[i]) << " ";
    }
    cout << "\n";
}