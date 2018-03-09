/*
    Codeforces Problem 514C: Watto and Mechanism (http://codeforces.com/problemset/problem/514/C)
    Author: arvindr9
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxk = 1000000; //max value of a string's length
int n, m;
int slen = 0; //the length of the string that was previously processed: used to efficiently zero out the dp arrays
const ll p = 1000000007;
const ll x = 42863052;
const ll x2 = 47825835;
set<ll> set1;
map<ll, set<char>> mapc; 
map<ll, set<int>> mapi;
set<ll> set2;
map<ll, set<char>> mapc2;
map<ll, set<int>> mapi2;
ll h, h2, poww[maxk], poww2[maxk];

void constructPow() {
    ll num = 1;
    ll num2 = 1;
    for(int i = 0; i < maxk; i++) {
        poww[i] = num, poww2[i] = num2;
        num *= x, num2 *= x2;
        num %= p, num2 %= p;
    }
}

void constructHashes(string s) {
    int len = s.size();
    h = h2 = s[0] - '0';
    for(int i = 1; i < len; i++) {
        ll c = s[i] - '0';
        h = (h * x + c) % p;
        h2 = (h2 * x2 + c) % p;
    }
}

void insertHashes(string s) {
    constructHashes(s);
    int len = s.size();
    for(int i = 0; i < len; i++) {
        ll hash = (h - ((s[i] - '0') * poww[len - i - 1]) % p + p) % p;
        ll hash2 = (h2 - ((s[i] - '0') * poww2[len - i - 1]) % p + p) % p;
        set1.insert(hash);
        mapc[hash].insert(s[i]);
        mapi[hash].insert(i);
        set2.insert(hash2);
        mapc2[hash2].insert(s[i]);
        mapi2[hash2].insert(i);
    }
}

void checkValidity(string s) {
    int len = s.size();
    constructHashes(s);
    for(int i = 0; i < len; i++) {
        ll hash = (h - ((s[i] - '0') * poww[len - i - 1]) % p + p) % p;
        ll hash2 = (h2 - ((s[i] - '0') * poww2[len - i - 1]) % p + p) % p;
        unsigned int req_size = 1 + (mapc[hash].count(s[i]) ? 1 : 0);
        unsigned int req_size2 = 1 + (mapc2[hash2].count(s[i]) ? 1 : 0);
        if(set1.count(hash) && (mapc[hash].size() >= req_size) && mapi[hash].count(i)
            && set2.count(hash2) && (mapc2[hash2].size() >= req_size2) && mapi2[hash2].count(i)) { //hash already exists, different characters were used to hash, hashes were done at the same indices. Issue: there exists another string that produces the same hash value when an index is removed.
            cout << "YES\n";
            return;
        } 
    }
    cout << "NO\n";
}

int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
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
