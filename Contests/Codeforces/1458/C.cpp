// CF 1458 C

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

int reduce(int n, int mod) {
    return (n %= mod) < 0 ? n + mod : n;
}

int n, m;

array<int, 3> simplify(array<int, 3> a) {
    array<int, 3> res = {reduce(a[0], n), reduce(a[1], n), reduce(a[2], n)};
    return res;
}
array<int, 3> add(array<int, 3> a, array<int, 3> b) {
    array<int, 3> res = {a[0] + b[0], a[1] + b[1], a[2] + b[2]};
    return simplify(res);
}
array<int, 3> mult(array<int, 3> a, int c) {
    array<int, 3> res = {a[0] * c, a[1] * c, a[2] * c};
    return simplify(res);
}

void process(string &st, int m, array<int, 3> &cur_coord) {
    for (int i = 0; i < m; i++) {
        if (st[i] == 'D') cur_coord[0]++;
        else if (st[i] == 'U') cur_coord[0]--;
        else if (st[i] == 'R') cur_coord[1]++;
        else if (st[i] == 'L') cur_coord[1]--;
        else if (st[i] == 'I') swap(cur_coord[1], cur_coord[2]);
        else if (st[i] == 'C') swap(cur_coord[0], cur_coord[2]);
        cur_coord = simplify(cur_coord);
    }
}

void process2(string &st, int m, array<int, 3> &cur_coord) {
    for (int i = 0; i < m; i++) {
        if (st[i] == 'I') swap(cur_coord[1], cur_coord[2]);
        else if (st[i] == 'C') swap(cur_coord[0], cur_coord[2]);
    }
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                a[i][j]--;
            }
        }
        vector<array<int, 3>> coords;

        array<int, 3> cur_coord = {0, 0, a[0][0]};
        array<int, 3> origin = {0, 0, 0};
        array<int, 3> vx = {1, 0, 0};
        array<int, 3> vy = {0, 1, 0};
        array<int, 3> vz = {0, 0, 1};
        
        string st;
        cin >> st;
        process(st, m, origin), process2(st, m, vx), process2(st, m, vy), process2(st, m, vz);

        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int v = a[i][j];
                array<int, 3> offsetx = mult(vx, i);
                array<int, 3> offsety = mult(vy, j);
                array<int, 3> offsetz = mult(vz, v);
                array<int, 3> ans = add(origin, add(offsetx, add(offsety, offsetz)));
                res[ans[0]][ans[1]] = ans[2] + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

    }
} 