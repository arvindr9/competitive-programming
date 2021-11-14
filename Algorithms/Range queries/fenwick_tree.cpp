// Source: https://judge.yosupo.jp/submission/54415

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


const int maxn = 5e5 + 5;
int bit[maxn];

int get(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        res += bit[i];
    }
    return res;
}

void update(int pos, int delta) {
    for (int i = pos; i < maxn; i += i & -i) {
        bit[i] += delta;
    }
}

int ln = 20;

int lastLeq(int sm) {
    int pos = 0;
    int cursum = 0;
    for (int i = ln; i >= 0; i--) {
        int cand = pos + (1<<i);
        if (cursum + bit[cand] <= sm) {
            cursum += bit[cand];
            pos = cand;
        }
    }
    return pos;
}

int query(int l, int r) {
    return get(r) - get(l - 1);
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(i, x);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            l++;
            // cout << "l: " << l << ", r: " << r << "\n";
            cout << query(l, r) << "\n";
        } else {
            int p, x;
            cin >> p >> x;
            p++;
            update(p, x);
        }
    }

} 