#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
	if (sz(pts) <= 1) return pts;
	sort(all(pts));
	vector<P> h(sz(pts)+1);
	int s = 0, t = 0;
	for (int it = 2; it--; s = --t, reverse(all(pts)))
		for (P p : pts) {
			while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
			h[t++] = p;
		}
	return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

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
    int n, m;
    cin >> n >> m;
    vector<int> amt(n);
    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        cin >> amt[i] >> time[i];
    }

    vector<P> pts;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        pts.eb(x, y);
    }

    vector<P> hull = convexHull(pts);
    long double req = 0;
    for (int i = 0; i < (int)hull.size(); i++) {
        int nexti = (i + 1) % (int)hull.size();
        req += (hull[nexti] - hull[i]).dist();
    }
    int required = ceil(req); //this will be at most 4K
    // cout << "required: " << required << "\n";

    int maxn = 8005;
    vector<int> dp(maxn); // dp[i]: min amount of time to get i amount from trees
    fill(dp.begin(), dp.end(), inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = maxn - 1; j >= 0; j--) {
            int nexti = j + amt[i - 1];
            if (nexti < maxn) {
                dp[nexti] = min(dp[nexti], dp[j] + time[i - 1]);
            }
        }
    }
    int ans = inf;
    for (int i = required; i < maxn; i++) {
        ans = min(ans, dp[i]);
    }
    for (int i = 0; i < n; i++) {
        if (amt[i] >= required) ans = min(ans, time[i]);
    }
    cout << ans << "\n";
} 