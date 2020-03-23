#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;

// template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

// https://codeforces.com/contest/1326/submission/73749710

const int maxn = 1e6 + 5;
int t;

const ll B = 1e9  + 7;
const ll mod = 998244353;
const ll A = 1e9 + 9;
ll h1[2][maxn], h2[2][maxn];
ll poww1[maxn], poww2[maxn];
string st, str;
int len;

ll prod(ll a, ll b) {
    return (((a * b) % mod) + mod) % mod;
}

ll add(ll a, ll b) {
    return (((a + b) % mod) + mod) % mod;
}

void precomp() {
    poww1[0] = poww2[0] = 1;
    for (int i = 1; i < maxn; i++) {
        poww1[i] = prod(poww1[i - 1], A);
        poww2[i] = prod(poww2[i - 1], B);
    }
}

void make_hashes() {
    ll res = 1;
    h1[0][0] = h2[0][0] = st[0] - 'a' + 1;
    h1[1][0] = h2[1][0] = str[0] - 'a' + 1;
    for (int i = 1; i < len; i++) {
        h1[0][i] = add(prod(h1[0][i - 1], A), st[i] - 'a' + 1);
        h1[1][i] = add(prod(h1[1][i - 1], A), str[i] - 'a' + 1);
        h2[0][i] = add(prod(h2[0][i - 1], B), st[i] - 'a' + 1);
        h2[1][i] = add(prod(h2[1][i - 1], B), str[i] - 'a' + 1);
    }
}

ll get_hash1(int rev, int l, int r) {
    if (l == 0) {
        return h1[rev][r];
    }
    return add(h1[rev][r], -prod(poww1[r - l + 1], h1[rev][l - 1]));
}

ll get_hash2(int rev, int l, int r) {
    if (l == 0) {
        return h2[rev][r];
    }
    return add(h2[rev][r], -prod(poww2[r - l + 1], h2[rev][l - 1]));
}

bool is_pal(int l, int r) {
    return get_hash1(0, l, r) == get_hash1(1, len - 1 - r, len - 1 - l);
        // && get_hash2(0, l, r) == get_hash2(1, len - 1 - r, len - 1 - l);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    precomp();
    for (int cs = 1; cs <= t; cs++) {
        cin >> st;
        len = st.size();
        str = "";
        for (int i = len - 1; i >= 0; i--) {
            str += st[i];
        }
        make_hashes();
        int l = 0;
        int r = len - 1;
        while (l < r && st[l] == st[r]) {
            l++;
            r--;
        }
        //now l <= r
        int l2 = -2;
        int r2 = -3;
        int maxval = 0;
        int ll = 3;
        int rr = 5;
        for (int i = l; i <= r; i++) {
            if (is_pal(l, i)) {
                int calc = i - l + 1;
                if (calc > maxval) {
                    l2 = l;
                    r2 = i;
                    maxval = calc;
                }
            }
            if (is_pal(i, r)) {
                int calc = r - i + 1;
                if (calc > maxval) {
                    l2 = i;
                    r2 = r;
                    maxval = calc;
                }
            }
        }

        for (int i = 0; i < l; i++) {
            cout << st[i];
        }
        for (int i = l2; i <= r2; i++) {
            cout << st[i];
        }
        for (int i = r + 1; i < len; i++) {
            cout << st[i];
        }
        cout << "\n";
    }


}
