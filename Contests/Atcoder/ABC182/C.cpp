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

int reduce(int a, int m) {
    return a % m < 0 ? a + m: a;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string st;
    cin >> st;
    vector<int> res(3);
    int n = st.size();
    int total_res = 0;
    for (int i = 0; i < n; i++) {
        int residue = (st[i] - '0') % 3;
        res[residue]++;
        total_res += residue;
        total_res %= 3;
    }
    // cout << "total_res: " << total_res << "\n";
    if (total_res == 0) {
        cout << 0 << "\n";
        return 0;
    }
    if (n == 1) {
        cout << -1 << "\n";
        return 0;
    }

    int want = total_res;
    // cout << "want: " << want << "\n";

    if (res[want]) {
        cout << 1 << "\n";
        return 0;
    }

    if (n <= 2) {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            if ((i + j) % 3 == want) {
                if (i != j) {
                    if (res[i] and res[j]) {
                        cout << 2 << "\n";
                        return 0;
                    }
                } else {
                    if (res[i] >= 2) {
                        cout << 2 << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << -1 << "\n";

}