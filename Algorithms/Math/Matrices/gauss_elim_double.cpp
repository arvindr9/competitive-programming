/*
Gaussian elimination for doubles
TODO: get this to AC in https://www.spoj.com/problems/GS/
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double T;

const ll mod = 1e9 + 7;
const double EPS = 1e-9;
const int INF = 2;
#define double long double

ll reduce(ll a) {
    return ((a % mod) + mod) % mod;
}

ll prod(ll a, ll b) {
    return reduce(a * b);
}

ll add(ll a, ll b) {
    return reduce(a + b);
}

struct matrix {
    int n, m;
    vector<vector<T>> mat;
    matrix(int _n, int _m) {
        n = _n;
        m = _m;
        mat.resize(n, vector<T>(m));
    }
    matrix(vector<vector<T>> &v) {
        n = v.size();
        m = v[0].size();
        mat.resize(n, vector<T>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = v[i][j];
            }
        }
    }
    matrix(const matrix &mm) {
        n = mm.n;
        m = mm.m;
        mat.resize(n, vector<T>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = mm.mat[i][j];
            }
        }
    }

    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // implementation for gaussian elimination based on cp-algorithms -- O(n^3)
    int gauss_elim_slow(vector<T> &ans) {
        int n = mat.size();
        int m = mat[0].size() - 1;

        vector<int> where(m, -1);
        // cout << "n: " << n << ", m: " << m << "\n";

        for (int col = 0, row = 0; col < m and row < n; col++) {
            int sel = row;
            for (int i = row; i < n; i++) {
                if (abs(mat[i][col]) > abs(mat[sel][col])) {
                    sel = i;
                }
            }
            // cout << "sel: " << sel << "\n";
            if (abs(mat[sel][col] < EPS)) continue;
            for (int i = col; i <= m; i++) {
                swap(mat[row][i], mat[sel][i]);
            }
            where[col] = row;
            // cout << "where: " << where[col] 
            double c = mat[row][col];
            for (int i = col; i <= m; i++) {
                mat[row][i] /= c;
            }
            for (int i = 0; i < n; i++) {
                if (i != row) {
                    double c = mat[i][col] / mat[row][col];
                    for (int j = col; j <= m; j++) {
                        mat[i][j] -= c * mat[row][j];
                    }
                }
            }
            // cout << "columns finished: " << col << "\n";
            // print();
            row++;
        }
        ans.resize(m, -1);
        for (int i = 0; i < m; i++) {
            if (where[i] != -1) {
                ans[i] = mat[where[i]][m] / mat[where[i]][i];
            }
        }
        for (int i = 0; i < n; i++) {
            double sm = 0;
            for (int j = 0; j < m; j++) {
                sm += mat[i][j] * ans[j];
            }
            if (abs(sm - mat[i][m]) > EPS) return 0;
        }
        for (int i = 0; i < m; i++) {
            if (where[i] == -1) return INF;
        }
        return 1;
    }

    int gauss_elim_fast(vector<int> &ans) {
        int n = mat.size();
        int m = mat[0].size() - 1;
        // downward pass
        for (int row = 0, col = 0; row < n and col < m; col++) {
            int sel = row;
            for (int i = row; i < n; i++) {
                if (mat[i][col] > mat[sel][col]) {
                    sel = i;
                }
            }
            if (abs(mat[sel][col]) > EPS) continue;
            for (int i = col; i <= m; i++) {
                swap(mat[row][i], mat[sel][i]);
            }
            double c = mat[row][col]
            for (int i = col; i <= m; i++) {
                mat[row][i] /= c;
            }
            for (int i = row + 1; i < n; i++) {
                double c = mat[i][col] / mat[row][col];
                for (int j = col; j <= m; j++) {
                    mat[i][j] -= c * mat[row][col];
                }
            }
        }
        //upward pass: TODO later
    }
};

const int maxn = 105;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int n, s, e;
    cin >> n >> s >> e;
    s--;
    e--;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 1; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u - 1][v - 1] = c;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] and !adj[j][i]) {
                adj[j][i] = adj[i][j];
            }
        }
    }
    vector<vector<double>> transitions(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++) {
        if (i == e) {
            transitions[i][i] = 1;
            continue;
        }
        int sumc = 0;
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) {
                sumc += adj[i][j];
            }
        }
        for (int j = 0; j < n; j++) {
            if (j == i) {
                transitions[i][j] = sumc;
            } else {
                if (adj[i][j]) {
                    transitions[i][j] = -adj[i][j];
                }
            }
        }
        transitions[i][n] = sumc;
    }
    matrix transition_mat = matrix(transitions);
    // cout << "printing matrix:\n";
    // transition_mat.print();

    vector<double> ans;
    int num_sol = transition_mat.gauss_elim_slow(ans);
    // cout << "printing ans:\n";
    // for (int i = 0; i < n; i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << "\n";
    // cout << "num solutions: " << num_sol << "\n";
    cout << setprecision(5) << fixed << ans[s] << "\n";
    
    
}