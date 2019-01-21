#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> intervals;

ll n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll x, y; cin >> x >> y;
        if (!intervals.count(x - y)) intervals[x - y] = x + y;
        else intervals[x - y] = max(intervals[x - y], x + y);
    }
    ll ans = 0;
    ll maxR = -5e9;
    for (pair<ll, ll> p: intervals) {
        ll lef = p.first;
        if (intervals[lef] > maxR) { //a new peak is found
            ans++;
            maxR = intervals[lef];
        }
    }
    cout << ans << "\n";
}