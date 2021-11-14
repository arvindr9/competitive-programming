// AC'ed this problem: https://www.spoj.com/problems/NAJPF/

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


// taken from cp-algorithms
vector<int> prefix_function(string st) {
    int n = st.size();
    vector<int> last(n);
    for (int i = 1; i < n; i++) {
        int j = last[i - 1];
        while (j > 0 and st[i] != st[j]) {
            j = last[j - 1];
        }
        if (st[i] == st[j]) {
            j++;
        }
        last[i] = j;
    }
    return last;
}

void compute_automaton(string st, vector<vector<int>>& aut) {
    st += '#';
    int n = st.size();
    vector<int> last = prefix_function(st);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != st[i])
                aut[i][c] = aut[last[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == st[i]);
        }
    }
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        string st, tt;
        cin >> st >> tt;
        int n = st.size();
        int m = tt.size();
        string new_s = tt + '#' + st;
        vector<int> last = prefix_function(new_s);
        int len = m + 1 + n;
        vector<int> indices;
        for (int i = m + 1; i < len; i++) {
            // cout << "i: " << i << ", last: " << last[i] << "\n";
            if (last[i] == m) {
                indices.pb(i - m + 1 - (m + 1) + 1); // the last +1 is for one-indexing
            }
        }
        if (indices.size()) {
            cout << indices.size() << "\n";
            for (int idx: indices) {
                cout << idx << " ";
            }
            cout << "\n";
        }   else {
            cout << "Not Found\n";
        }
    }
} 