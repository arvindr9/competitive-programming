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

int reduce(int a) {
    return (a %= 4) < 0 ? a + 4: a;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string st;
    int par = 0;
    cin >> n >> st;
    for (int i = 0; i < n; i++) {
        if (st[i] == 'B') par++;
        else par--;
    }

    int black_reduce = reduce(n);
    int white_reduce = reduce(-n);
    int par_reduce = reduce(par);
    char target;
    if (par_reduce == black_reduce) {
        target = 'B';
    } else if (par_reduce == white_reduce) {
        target = 'W';
    } else {
        cout << -1 << "\n";
        return 0;
    }
    // cout << "target: " << target << "\n";

    if (abs(par) == n) {
        cout << 0 << "\n";
        return 0;
    }
    vector<int> ans;
    for (int i = 0; i < n - 1; i++) {
        if (st[i] != target) {
            if (st[i + 1] != target) {
                ans.pb(i);
                st[i] = st[i + 1] = target;
            } else {
                ans.pb(i);
                swap(st[i], st[i + 1]);
            }
        }
    }

    cout << ans.size() << "\n";
    for (int i: ans) {
        cout << (i + 1) << " ";
    }
    cout << "\n";
} 