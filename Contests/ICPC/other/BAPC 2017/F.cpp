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
#define inf 1e18

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int> pq;;
    vector<int> ss(2);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }
    int i = 0;
    while (!pq.empty()) {
        int a = pq.top();
        pq.pop();
        ss[i] += a;
        i ^= 1;
    }
    cout << ss[0] << " " << ss[1] << "\n";
} 