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
#define INF 1e18

int t;

int eval(int x) {
    int ans = x;
    string st = to_string(x);
    for (int i = 0; i < (int)st.size(); i++) {
        ans += st[i] - '0';
    }
    return ans;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = max(1LL, n - 100); i <= n; i++) {
        if (eval(i) == n) {
            ans.pb(i);
        }
    }
    cout << ans.size() << "\n";
    for (int elt: ans) {
        cout << elt << " ";
    }
    cout << "\n";
} 