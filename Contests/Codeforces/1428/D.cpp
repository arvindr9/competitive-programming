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

vector<pi> nonzeros;
int a[maxn];
int taken[maxn];
int visited[maxn];
int n;

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    cin >> n;
    bool possible = true;
    vector<int> ones;
    vector<int> twos;
    vector<int> threes;
    vector<pi> targets;
    int curi = n;
    priority_queue<int> open; // for future placements of threes
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i > 0; i--) {
        if (a[i] == 1) {
            ones.pb(i);
        } else if (a[i] == 2) {
            twos.pb(i);
        } else if (a[i] == 3) {
            threes.pb(i);
        }
        if (twos.size() > ones.size()) {
            possible = false;
            break;
        }
        if (!ones.empty() and !twos.empty()) {
            targets.pb({curi, twos.back()});
            targets.pb({curi, ones.back()});
            visited[twos.back()] = visited[ones.back()] = 1;
            open.push(twos.back());
            curi--;
            twos.pop_back();
            ones.pop_back();
        }
    }

    if (a[n] == 3) {
        possible = false;
    }

    if (!possible) {
        cout << -1 << "\n";
        return 0;
    }

    // cout << "passed first possible\n";
    // now left with ones and threes

    for (int i = n; i > 0; i--) {
        // cout << "curi: " << curi << "\n";
        if (!visited[i]) {
            if (curi < 1) {
                possible = false;
                break;
            }
            if (a[i] == 1) {
                targets.pb({curi, i});
                open.push(i);
                curi--;
            } else if (a[i] == 3) {
                targets.pb({curi, i});
                // cout << "i: " << i << ", open size: " << open.size() << "\n";
                if (open.empty()) {
                    possible = false;
                    break;
                }
                int nxt = open.top();
                if (nxt <= i) {
                    possible = false;
                    break;
                }
                open.pop();
                targets.pb({curi, nxt});
                open.push(i);
                curi--;
            }
        }
        visited[i] = 1;
    }

    
    if (possible) {
        cout << targets.size() << "\n";
        for (pi target: targets) {
            cout << target.f << " " << target.s << "\n";
        }
    } else {
        cout << "-1\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/