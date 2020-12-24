#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;
typedef priority_queue<int, vector<int>, greater<int> > min_heap;

// template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

mt19937_64 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

const int maxn = 1e6 + 5;
int loss[maxn], cuts[maxn], t[maxn];
int n, k;

int a[maxn];


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        t[i] = a[i] * a[i];
    }

    priority_queue<pi> pq;

    for (int i = 1; i <= n; i++) {
        if (a[i] > 1) {
            int half_a = a[i] / 2;
            int nxt_val = half_a * half_a + (a[i] - half_a) * (a[i] - half_a);
            loss[i] = t[i] - nxt_val;
            pq.push({loss[i], i});
        }
    }

    for (int cut = 1; cut <= k - n; cut++) {
        pi opt = pq.top();
        pq.pop();
        int ls = opt.f;
        int i = opt.s;
        // cout << "cutting " << i << "\n";
        // cout << "loss: " << ls << ", i: " << i << "\n";
        t[i] -= ls;
        cuts[i]++;
        if (cuts[i] < a[i] - 1) {
            //a[i] = p * (cuts + 1) + r;
            int p = a[i] / (cuts[i] + 2);
            int r = a[i] % (cuts[i] + 2);
            // cout << "p: " << p << ", r: " << r << "\n";
            int next_time = 0;
            next_time = r * (p + 1) * (p + 1);
            next_time += (cuts[i] + 2 - r) * p * p;
            // if (r == 0) {
            //     next_time = (p - 1) * (p - 1) * (cuts[i] + 1);
            //     next_time += (cuts[i] + 1) * (cuts[i] + 1);
            // } else {
            //     next_time = p * p * (cuts[i] + 1) + r * r;
            // }
            // cout << "next_time: " << next_time << "\n";
            loss[i] = t[i] - next_time;
            pq.push({loss[i], i});
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += t[i];
    }
    cout << ans << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/