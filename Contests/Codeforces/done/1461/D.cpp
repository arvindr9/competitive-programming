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

int t;

// int i = 0;
void process(vector<int> v, set<int> &results) {
    // i++;
    // if (i > 10) return;
    int sm = 0;
    for (int elt: v) sm += elt;
    results.insert(sm);
    // cout << "sm: " << sm << "\n";
    if ((int)v.size() == 1) return;
    int min_elt = *(min_element(v.begin(), v.end()));
    int max_elt = *(max_element(v.begin(), v.end()));
    int mid = (min_elt + max_elt) / 2;
    // cout << "min elt: " << min_elt << ", max elt: " << max_elt << "mid: "  << mid << "\n";
    if (min_elt == max_elt) {
        // cannot divide further
        return;
    }
    vector<int> v0;
    vector<int> v1;
    for (int elt: v) {
        if (elt <= mid) {
            v0.pb(elt);
        } else {
            v1.pb(elt);
        }
    }
    process(v0, results);
    process(v1, results);
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<int> qs(q);
        for (int i = 0; i < q; i++) {
            cin >> qs[i];
        }
        // int max_elt = *(max_element(v.begin(), v.end()));
        set<int> results;
        process(v, results);
        for (int i = 0; i < q; i++) {
            if (results.count(qs[i])) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
} 