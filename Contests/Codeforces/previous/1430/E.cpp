#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;
typedef priority_queue<int, vector<int>, greater<int> > min_heap;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

mt19937_64 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

const int maxn = 2e5 + 5;
int t;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

vector<int> indices[27];
int cur_index[27];

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    int n;
    cin >> n;
    string st;
    cin >> st;
    string dest;
    for (int i = n - 1; i >= 0; i--) {
        dest += st[i];
    }

    FT offset(n);

    for (int i = 0; i < n; i++) {
        indices[st[i] - 'a'].pb(i);
    }

    int ans = 0;



    for (int i = 0; i < n; i++) {
        int goal = dest[i] - 'a';
        int goal_idx = indices[goal][cur_index[goal]];
        // cout << "i: " << i << ", goal idx: " << goal_idx << ", offset: " << offset.query(goal_idx + 1) << "\n";
        int delta_ans = goal_idx + offset.query(goal_idx + 1) - i;
        ans += delta_ans;
        // cout << "i: " << i << ", ans: " << ans << "\n";
        if (delta_ans > 0) {
            offset.update(0, +1);
            offset.update(goal_idx + 1, -1);
        }
        // cout << "idx: " << indices[goal] << "\n";
        cur_index[goal]++;
    }

    cout << ans << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/