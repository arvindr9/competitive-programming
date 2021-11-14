#include <bits/stdc++.h>
using namespace std;



class BuyOneGetOneFree {

typedef int int2;
#define int long long
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
const int inf = 1e18;

public:
    int buy(vector<int> prices) {
        sort(prices.begin(), prices.end());
        int n = prices.size();
        int ans = 0;
        for (int i = n - 1; i >= 0; i-=2) {
            ans += prices[i];
        }
        return ans;
    }
};