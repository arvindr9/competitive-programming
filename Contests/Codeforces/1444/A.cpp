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
int t;

map<ll, int> pfac(ll a) {
  map<ll, int> res;
  for (int i = 2; i * i <= a; i++) {
    while (a % i == 0) {
      res[i]++;
      a /= i;
    }
  }
  if (a > 1) {
    res[a]++;
  }
  return res;
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> t;
    while (t--) {
        int p, q;
        cin >> p >> q;
        if (p % q != 0) {
            cout << p << "\n";
            continue;
        }
        int ans = 1;
        map<int, int> q_factors = pfac(q);
        for (pi pr: q_factors) {
            int pwr = 1;
            for (int i = 1; i <= pr.s; i++) {
                pwr *= pr.f;
            }
            int p_copy = p;
            while (p_copy % pwr == 0) {
                p_copy /= pr.f;
            }
            ans = max(ans, p_copy);
        }
        cout << ans << "\n";
        
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/

