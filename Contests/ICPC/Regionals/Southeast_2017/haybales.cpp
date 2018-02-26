#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2050;
const int large = 987654321;

map<int, deque<ll>> maxdpi;
map<int, deque<ll>> maxdpj;
ll dp[maxn][maxn];
bool accessible[maxn][maxn];
int n, k;

int main() {
    //freopen("haybales.in", "r", stdin);
    //freopen("haybales.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = large;
        }
    }
    dp[n][n] = 0;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= n; j++) {
            accessible[i][j] = ( s[j-1] == '.' ? true : false);
        }
    }
    for(int j = n; j >= 1; j--) {
        for(int i = n; i >= 1; i--) {
            if(j + k + 1 <= n && maxdpi[i].size() != 0 && maxdpi[i].front() == dp[i][j+k+1]) {
                maxdpi[i].pop_front();
            }
            if(i + k + 1 <= n && maxdpj[j].size() != 0 && maxdpj[j].front() == dp[i+k+1][j]) {
                maxdpj[j].pop_front();
            }
            if(!accessible[i][j]) continue;
            if(maxdpi[i].size() != 0) dp[i][j] = min(dp[i][j], 1 + maxdpi[i].front());
            if(maxdpj[j].size() != 0) dp[i][j] = min(dp[i][j], 1 + maxdpj[j].front());
            while(maxdpi[i].size() != 0 && dp[i][j] < maxdpi[i].back()) {
                maxdpi[i].pop_back();
            }
            maxdpi[i].push_back(dp[i][j]);
            while(maxdpj[j].size() != 0 && dp[i][j] < maxdpj[j].back()) {
                maxdpj[j].pop_back();
            }
            maxdpj[j].push_back(dp[i][j]);
        }
    }
    if(dp[1][1] == large) dp[1][1] = -1;
    cout << dp[1][1] << "\n";
}
