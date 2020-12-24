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

int t, x;

void append(vector<int> &a, vector<int>&c) {
    for (int elt: c) a.pb(elt);
}

void paste(int idx, vector<int> &a) {
    vector<int> c;
    int n = a.size() - 1;
    if (a[idx] == 1) return;
    for (int i = idx + 1; i <= n; i++) {
        c.pb(a[i]);
    }
    for (int i = 1; i <= a[idx] - 1; i++) {
        append(a, c);
        if ((int)a.size() >= x + 1) return;
    }
}

const int mod = 1e9 + 7;
int reduce(int a) {
    return (a %= mod) < 0 ? a + mod: a;
}

int add(int a, int b) {
    return reduce(a + b);
}

int prod(int a, int b) {
    return reduce(a * b);
}

void print(vector<int> &a) {
    for (int elt: a) {
        cout << elt << " ";
    }
    cout << "\n";
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> x;
        string st;
        cin >> st;
        int n = st.size();
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            a[i] = st[i - 1] - '0';
        }
        // print(a);
        for (int i = 1; i <= x; i++) {
            paste(i, a);
            if ((int)a.size() >= x + 1) break;
            // print(a);
        }
        // for (int i = 1; i <= n; i++) {
        //     paste(i, a);
        //     print(a);
        //     if ((int)a.size() >= x + 1) break;
        // }
        int total_size = n;
        for (int i = 1; i <= x; i++) {
            int c_size = total_size - i;
            total_size = add(total_size, prod(c_size, a[i] - 1));
        }
        cout << total_size << "\n";
    }
} 