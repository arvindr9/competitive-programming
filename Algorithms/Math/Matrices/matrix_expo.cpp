/*
Matrix exponentiation code
Verified in https://cses.fi/problemset/task/1723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

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
    vector<vector<ll>> mat;
    matrix(int _n, int _m) {
        n = _n;
        m = _m;
        mat.resize(n, vector<ll>(m));
    }
    matrix(vector<vector<ll>> &v) {
        n = v.size();
        m = v[0].size();
        mat.resize(n, vector<ll>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = v[i][j];
            }
        }
    }
    matrix(const matrix &mm) {
        n = mm.n;
        m = mm.m;
        mat.resize(n, vector<ll>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = mm.mat[i][j];
            }
        }
    }
    matrix operator +(const matrix &b) const {
        matrix c(*this);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                c.mat[i][j] = add(c.mat[i][j], b.mat[i][j]);
            }
        }
        return c;
    }
    matrix operator *(const ll a) const {
        matrix b(*this);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b.mat[i][j] = prod(b.mat[i][j], a);
            }
        }
        return b;
    }

    matrix operator*(const matrix &b) {
        matrix c(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    c.mat[i][j] = add(c.mat[i][j], prod(mat[i][k], b.mat[k][j]));
                }
            }
        }
        return c;
    }

    matrix id(int n) {
        matrix a = matrix(n, n);
        for (int i = 0; i < n; i++) {
            a.mat[i][i]++;
        }
        return a;
    }

    matrix expo(int pw) {
        if (pw == 0) {
            return id(n);
        }
        if (pw % 2 == 0) {
            matrix res = expo(pw / 2);
            return res * res;
        }
        return (*this) * expo(pw - 1);
    }

    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

const int maxn = 105;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> adj(n, vector<ll>(n));

    vector<vector<ll>> initial(n, vector<ll>(1));
    initial[0][0] = 1;
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v - 1][u - 1]++;
    }

    matrix m0 = matrix(initial);
    matrix transition = matrix(adj);

    matrix final_mat = transition.expo(k) * m0;
    cout << final_mat.mat[n - 1][0] << "\n";

    
}