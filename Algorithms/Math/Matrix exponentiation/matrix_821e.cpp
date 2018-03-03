/*
    Codeforces Problem 821E Okabe and El Psy Kongroo
    Round #420 Div 2 Problem E
    Author: arvindr9
*/

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
const ll MAX = 30;
const ll MAXN = 150;
const ll MOD = 1000000007;

inline ll add(ll x, ll y) {
    ll res = x + y;
    if(res >= MOD) res -= MOD;
    return res;
}

inline ll prod(ll x, ll y) {
    long long res = x * 1LL * y;
    if(res >= MOD) res %= MOD;
    return res;
}

struct matrix {
    ll mat[MAX][MAX];
    matrix(ll m = MAX - 1) {
        for(ll i = 0; i <= m; i++) {
            for(ll j = 0; j <= m; j++) {
                mat[i][j] = 0;
            }
        }
    }
};

matrix multiply(matrix a, matrix b) {
    matrix res;
    for(ll i = 0; i < MAX; i++) {
        for(ll j = 0; j < MAX; j++) {
            for(ll k = 0; k < MAX; k++) {
                res.mat[i][j] = add(res.mat[i][j], prod(a.mat[i][k], b.mat[k][j]));
            }
        }
    }
    return res;
}

matrix exponentiate(matrix a, ll p) {
    matrix res;
    for(ll i = 0; i < MAX; i++) {
        res.mat[i][i] = 1;
    }
    while(p) {
        if(p&1) {
            res = multiply(a, res);
        }
        a = multiply(a, a);
        p /= 2;
    }
    return res;
}
ll n, k;
ll a[MAXN], b[MAXN], c[MAXN];
matrix vec;
matrix sq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    ll i = 1;
    vec.mat[0][0] = 1;
    ll curr = 0;
    ll next = 0;
    for(i = 1; i <= n; i++) {
        curr = a[i];
        next = b[i] - 1;
        if(curr != next) {
            matrix transition;
            transition.mat[0][0] = transition.mat[0][1] = 1;
            ll ii = 1;
            for(ii = 1; ii <= c[i]; ii++) {
                transition.mat[ii][ii - 1] = transition.mat[ii][ii] = transition.mat[ii][ii + 1] = 1;
            }
            if(i < n) {
                vec = multiply(exponentiate(transition, next - curr), vec);
            } else if(i == n) {
                vec = multiply(exponentiate(transition, k - curr), vec);
                break;
            }
        }
        if(i == n && curr != next) break;
        if(k == curr) break;
        matrix transition2;
        transition2.mat[0][0] = transition2.mat[0][1] = 1;
        ll ii = 1;
        for(ii = 1; ii <= min(c[i], c[i+1]); ii++) {
            transition2.mat[ii][ii-1] = transition2.mat[ii][ii] = transition2.mat[ii][ii+1] = 1;
        }
        vec = multiply(transition2, vec);
    }
    cout << vec.mat[0][0] << "\n";

}