#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1000000;
const int maxk = 10000;
int n, m;
const ll p = 1000000007;
set<ll> set1;
set<ll> set2;
set<ll> set3;
const ll x = 345678894;
const ll x2 = 832659923;
const ll x3 = 326918759;
ll dp[maxk], dp2[maxk], dp3[maxk], poww[maxk], poww2[maxk], poww3[maxk];

void constructPow() {
    ll num = 1;
    ll num2 = 1;
    ll num3 = 1;
    for(int i = 0; i < maxk; i++) {
        poww[i] = num, poww2[i] = num2, poww3[i] = num3;
        num *= x, num2 *= x2, num3 *= x3;
        num %= p, num2 %= p, num3 %= p;
    }
}

void constructDp(string s) {
    for(int i = 0; i < 10000; i++) {
        dp[i] = dp2[i] = dp3[i] = 0LL;
    }
    int len = s.size();
    ll hash = s[0] - '0';
    ll hash2 = s[0] - '0';
    ll hash3 = s[0] - '0';
    dp[0] = dp2[0] = dp3[0] = hash;
    for(int i = 1; i < len; i++) {
        ll c = s[i] - '0';
        hash = (hash * x + c) % p;
        hash2 = (hash2 * x2 + c) % p;
        hash3 = (hash3 * x3 + c) % p;
        dp[i] = hash, dp2[i] = hash2, dp3[i] = hash3;
    }
}

void insertHashes(string s) {
    constructDp(s);
    int len = s.size();
    ll hash = (dp[len - 1] - (dp[0] * poww[len - 1]) % p + p) % p;
    ll hash2 = (dp2[len - 1] - (dp2[0] * poww2[len - 1]) % p + p) % p;
    ll hash3 = (dp3[len - 1] - (dp3[0] * poww3[len - 1]) % p + p) % p;
    set1.insert(hash), set2.insert(hash2), set3.insert(hash3);
    for(int i = 1; i < len; i++) {
        hash = (dp[len - 1] - (dp[i] * poww[len - i - 1]) % p + (dp[i - 1] * poww[len - i]) % p + p) % p;
        hash2 = (dp2[len - 1] - (dp2[i] * poww2[len - i - 1]) % p + (dp2[i - 1] * poww2[len - i]) % p + p) % p;
        hash3 = (dp3[len - 1] - (dp3[i] * poww3[len - i - 1]) % p + (dp3[i - 1] * poww3[len - i]) % p + p) % p;
        set1.insert(hash), set2.insert(hash2), set3.insert(hash3);
    }
}

void checkValidity(string s) {
    int len = s.size();
    constructDp(s);
    ll hash = (dp[len - 1] - (dp[0] * poww[len - 1]) % p + p) % p;
    ll hash2 = (dp2[len - 1] - (dp2[0] * poww2[len - 1]) % p + p) % p;
    ll hash3 = (dp3[len - 1] - (dp3[0] * poww3[len - 1]) % p + p) % p;
    if(set1.count(hash) && set2.count(hash2) && set3.count(hash3)) {
        cout << "YES\n";
        return;
    }
    for(int i = 1; i < len; i++) {
        hash = (dp[len - 1] - (dp[i] * poww[len - i - 1]) % p + (dp[i - 1] * poww[len - i]) % p + p) % p;
        hash2 = (dp2[len - 1] - (dp2[i] * poww2[len - i - 1]) % p + (dp2[i - 1] * poww2[len - i]) % p + p) % p;
        hash3 = (dp3[len - 1] - (dp3[i] * poww3[len - i - 1]) % p + (dp3[i - 1] * poww3[len - i]) % p + p) % p;
        if(set1.count(hash) && set2.count(hash2) && set3.count(hash3)) {
            cout << "YES\n";
            return;
        }  
    }
    cout << "NO\n";
}

int main() {
    // freopen("C.in", "r", stdin);
    // freopen("C.out", "w", stdout);
    cin >> n >> m;
    constructPow();
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        insertHashes(s);
    }
    for(int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        checkValidity(s);
    }
}