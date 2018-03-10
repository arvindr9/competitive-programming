//hacked :(
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
queue<ll> q;
const int maxn = 200000;
int n;
ll T[maxn], V[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> V[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> T[i];
    }
    string s = "";
    for(int i = 1; i <= n; i++) {
        ll ans = 0;
        q.push(V[i]);
        int siz = q.size();
        for(int j = 1; j <= siz; j++) {
            ll rem = q.front(); q.pop();
            ans += min(rem, T[i]);
            rem = rem - min(rem, T[i]);
            if(rem > 0) {q.push(rem);}
        }
        string sadd;
        ostringstream oss;
        oss << ans;
        s += " " + oss.str();
    }
    s = s.substr(1);
    cout << s << "\n";
}
