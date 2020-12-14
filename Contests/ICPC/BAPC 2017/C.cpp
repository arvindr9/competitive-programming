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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = __gcd(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return __gcd(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

vector<int> compute(vector<int> &gcds, int elt) {
    vector<int> res;
    for (int i: gcds) {
        res.pb(__gcd(i, elt));
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

void print(vector<int> &v) {
    for (int elt: v) {
        cout << elt << " ";
    }
    cout << "\n";
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> cur_gcds = {a[n - 1]};
    set<int> gcds = {a[n - 1]};
    for (int i = n - 2; i >= 0; i--) {
        // print(cur_gcds);
        cur_gcds.pb(a[i]);
        cur_gcds = compute(cur_gcds, a[i]);
        for (int elt: cur_gcds) {
            gcds.insert(elt);
        }
    }
    
    // print(cur_gcds);

    int ans = gcds.size();
    cout << ans << "\n";
} 

