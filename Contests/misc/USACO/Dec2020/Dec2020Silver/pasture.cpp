#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


using namespace std;

#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int t;

const int maxn = 2505;
pi coords[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        coords[i] = {x, y};
    }

    sort(coords + 1, coords + n + 1);

    // let the cows be c1, c2, c3, ..., cn in increasing order of x-coordinate


    long long ans = 0;
    for (int l = 1; l <= n; l++) {
        int y1 = coords[l].s;
        indexed_set ys;
        for (int r = l; r <= n; r++) {
            // compute the number of ways to select a subset of cl, c_{l + 1}, ..., cr that includes cl and cr
            int y2 = coords[r].s;
            ys.insert(y2);
            int ymin = min(y1, y2), ymax = max(y1, y2);
            int num_distinct = r - l + 1;
            int ymax_index = ys.order_of_key(ymax);
            int ymin_index = ys.order_of_key(ymin);
            ans += (long long)(ymin_index + 1) * (long long)(num_distinct - ymax_index);
        }
    }
    cout << ans + 1 << "\n";
} 