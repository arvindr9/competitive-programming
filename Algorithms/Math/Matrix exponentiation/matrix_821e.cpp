#include <bits/stdc++.h>

using namespace std;

const int MAX = 30;
const int MAXN = 150;
const int MOD = 1000000007;

inline int add(int x, int y) {
    int res = x + y;
    if(res >= MOD) res -= MOD;
    return res;
}

inline int prod(int x, int y) {
    long long res = x * 1LL * y;
    if(res >= MOD) res %= MOD;
    return res;
}

struct matrix {
    int mat[MAX][MAX];
    matrix(int m = MAX - 1) {
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= m; j++) {
                mat[i][j] = 0;
            }
        }
    }
};

matrix multiply(matrix a, matrix b) {
    matrix res;
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            for(int k = 0; k < MAX; k++) {
                res.mat[i][j] = add(res.mat[i][j], prod(a.mat[i][k], b.mat[k][j]));
            }
        }
    }
    return res;
}

matrix exponentiate(matrix a, int p) {
    matrix res;
    for(int i = 0; i < MAX; i++) {
        res.mat[i][i] = 1;
    }
    while(p) {
        if(p&1) {
            res = multiply(a, res);
            a = multiply(a, a);
        }
        p /= 2;
    }
    return res;
}
int n, k;
int a[MAXN], b[MAXN], c[MAXN];
matrix vec;
matrix sq;


void print(matrix m, ofstream &fout) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            fout << m.mat[i][j] << " ";
        }
        fout << "\n";
    }
    fout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ofstream fout("m.out");
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    int i = 1;
    vec.mat[0][0] = 1;
    print(vec, fout);
    int curr = 0;
    int next = 0;
    for(i = 1; i <= n; i++) {
        curr = a[i];
        next = b[i] - 1;
        if(curr != next) {
            matrix transition;
            transition.mat[0][0] = transition.mat[0][1] = 1;
            int ii = 1;
            for(ii = 1; ii <= c[i]; ii++) {
                transition.mat[ii][ii - 1] = transition.mat[ii][ii] = transition.mat[ii][ii + 1] = 1;
            }
            if(i < n) {
                vec = multiply(exponentiate(transition, next - curr), vec);
                //print(vec, fout);
            } else if(i == n) {
                vec = multiply(exponentiate(transition, k - curr), vec);
                //print(vec, fout);
                break;
            }
        }
        matrix transition2;
        transition2.mat[0][0] = transition2.mat[0][1] = 1;
        int ii = 1;
        for(ii = 1; ii <= min(c[i], c[i+1]); ii++) {
            transition2.mat[ii][ii-1] = transition2.mat[ii][ii] = transition2.mat[ii][ii+1] = 1;
        }
        vec = multiply(transition2, vec);
        print(vec, fout);
    }
    cout << vec.mat[0][0] << "\n";

}