// Matthew Fahrbach
// January 18, 2018
// https://icpcgate.org/viewproblem.php?pid=1462

#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 222;
int n, V;
int v[MAXN], w[MAXN], c[MAXN];
 
vector<int> get_basis(int x) {
    int a = 0;
    int b = 1;
    vector<int> ans;
    while (2*b - 1 <= x) {
        ans.push_back(b);
        a += b;
        b *= 2;
    }
    if (x - a > 0) ans.push_back(x - a);
    return ans;
}
 
long long solve_knapsack(const vector<pair<int, int>>& items, int capacity) {
    vector<long long> dp(capacity + 1);
    for (int i = 0; i < items.size(); i++) {
        int weight = items[i].first;
        int value = items[i].second;
        for (int j = capacity; j >= 0; j--) {
            if (j >= weight) {
                dp[j] = max(dp[j], dp[j - weight] + value);
            }
        }
    }
    return dp[capacity];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> V;
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i] >> c[i];
    }
    vector< pair<int, int> > items;
    for (int i = 0; i < n; i++) {
        vector<int> basis = get_basis(c[i]);
        for (int j = 0; j < basis.size(); j++) {
            items.push_back(make_pair(basis[j]*v[i], basis[j]*w[i]));
        }
    }
    cout << solve_knapsack(items, V) << endl;
}
