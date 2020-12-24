//1464 B

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
const int inf = 1e18;

int t;

const int maxn = 1e5 + 5;
int bit[maxn];

void update(int pos, int delta) {
    for (int i = pos; i < maxn; i += i & -i) {
        bit[i] += delta;
    }
}

int get(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        res += bit[i];
    }
    return res;
}

vector<char> rev(vector<char> &v) {
    int n = v.size() - 1;
    vector<char> res(n + 1);
    for (int i = 1; i <= n; i++) {
        res[i] = v[n + 1 - i];
    }
    return res;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string ss;
    cin >> ss;
    int n = ss.size();
    vector<char> st(n + 1);
    for (int i = 1; i <= n; i++) {
        st[i] = ss[i - 1];
    }

    int x, y;
    cin >> x >> y;
    // cout << ss << " " << x << " " << y << "\n";

    if (x > y) {
        st = rev(st);
        swap(x, y);
    }
    // x <= y

    vector<int> q_inds;
    for (int i = 1; i <= n; i++) {
        if (st[i] == '?') q_inds.pb(i);
    }

    // set everything to ones (include question marks)

    vector<int> sufsum(n + 2);
    // if (st[n] != 0) sufsum[n] = 1; // doesn't do anything
    for (int i = n; i > 0; i--) {
        if (st[i] != '0') sufsum[i] = sufsum[i + 1] + 1, update(i, +1);
        else sufsum[i] = sufsum[i + 1];
    }
    int min_cost = 0;

    // compute cost
    int total_cost = 0;
    for (int i = 1; i <= n; i++) {
        if (st[i] == '0') {
            // 01 pairs
            total_cost += x * sufsum[i + 1];
        } else {
            // 10 pairs
            total_cost += y * (n - i - sufsum[i + 1]);
        }
        // cout << "i: " << i << ", total_cost: " << total_cost << "\n";
        // cout << "st[i]: " << st[i] << ", sufsum: " << sufsum[i + 1] << "\n";
    }
    min_cost = total_cost;
    // cout << "total_cost: " << total_cost << "\n";

    // set things to 0 one by 1

    for (int i: q_inds) {
        // cout << "i: "  << i << "\n";
        // remove original costs
        // 01 pairs
        total_cost -= x * (i - 1 - get(i - 1));
        // cout << "get: " << get(i - 1) << "\n";
        // cout << "total_cost: " << total_cost << "\n";
        // 10 pairs
        total_cost -= y * (n - i - sufsum[i + 1]);
        // cout << "total_cost: " << total_cost << "\n";
        update(i, -1);
        // 01 pairs
        total_cost += x * sufsum[i + 1];
        // cout << "total_cost: " << total_cost << "\n";
        // 10 pairs
        total_cost += y * get(i - 1);
        min_cost = min(min_cost, total_cost);
        // cout << "total_cost: " << total_cost << "\n";
        // cout << "\n";
    }
    
    cout << min_cost << "\n";

} 