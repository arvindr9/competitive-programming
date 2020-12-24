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

#ifndef M_PI
    #define M_PI 3.1415926535897932384626433832795028841971
#endif

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

typedef double T;

typedef Point<T> P;
double segDist(P& s, P& e, P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    T x, y;
    cin >> x >> y;
    Point<T> p(x, y);
    T min_dist = inf;
    T max_dist = 0;
    vector<Point<T>> pts;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        pts.eb(x, y);
        max_dist = max(max_dist, (pts.back() - p).dist2());
    }
    for (int i = 0; i < n; i++) {
        Point<T> p1 = pts[i];
        int i2 = (i + 1) % n;
        Point<T> p2 = pts[i2];
        min_dist = min(min_dist, segDist(p1, p2, p));
    }
    // cout << "min_dist: " << min_dist << ", max_dist: " << max_dist << "\n";
    long double ans = M_PI * (long double)(max_dist - min_dist * min_dist);
    cout << fixed << setprecision(10) << ans << "\n";
} 
