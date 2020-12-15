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

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}


template<class P> bool segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return true;
	set<P> s;
	return (onSegment(c, d, a) or onSegment(c, d, b) or onSegment(a, b, c) or onSegment(a, b, d));
}

typedef long double T;

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

typedef pair<Point<int>, Point<int>> line;

bool parallel(line &l1, line &l2) {
	// dy1 / dx1 = dy2 / dx2, i.e. dy1 * dx2 = dy2 * dx1
	int dy1 = l1.s.y - l1.f.y;
	int dx1 = l1.s.x - l1.f.x;
	int dy2 = l2.s.y - l2.f.y;
	int dx2 = l2.s.x - l2.f.x;
	return dy1 * dx2 == dy2 * dx1;
}

bool parallel_intersect(line l1, line l2) {
	if (!parallel(l1, l2)) return false;
	return segInter(l1.f, l1.s, l2.f, l2.s);
}

line merge(line&l1, line&l2) {
	line cand;
	double max_dist = 0;
	auto chkmax = [&](Point<int> &p1, Point<int> &p2) {
		if ((double)(p1 - p2).dist() > max_dist) {
			max_dist = (double)(p1 - p2).dist();
			cand = {p1, p2};
		}
		return;
	};
	chkmax(l1.f, l2.s);
	chkmax(l1.f, l2.f);
	chkmax(l1.s, l2.s);
	chkmax(l1.s, l2.f);
	chkmax(l1.f, l1.s);
	chkmax(l2.f, l2.s);
	return cand;
}

const int maxn = 1005;

int par[maxn];
int sz[maxn];
line rep[maxn];
int visited[maxn];

int find(int u) {
	if (u != par[u]) return par[u] = find(par[u]);
	return u;
}

void reset() {
	for (int i = 0; i < maxn; i++) {
		par[i] = i;
		sz[i] = 1;
	}
}

void unite(int u, int v) {
	u = find(u), v = find(v);
	if (sz[u] < sz[v]) {
		swap(u, v);
	}
	par[v] = u;
	sz[u] += sz[v];
	rep[u] = merge(rep[u], rep[v]);
}

void unite2(int u, int v) {
	u = find(u), v = find(v);
	if (sz[u] < sz[v]) {
		swap(u, v);
	}
	par[v] = u;
	sz[u] += sz[v];
}

int share(int u, int v) {
	return find(u) == find(v);
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	vector<line> segs(n);

	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		segs[i].f = Point<int>(x1, y1);
		segs[i].s = Point<int>(x2, y2);
		par[i] = i;
		sz[i] = 1;
		rep[i] = segs[i];
	}

	// merging parallel edges that intersect: apparently not necessary?
	// maybe has to do with the fact that no three lines intersect at a point, so maybe moving the edges away from each other doesn't delete / create faces?

	// for (int i = 0; i < n; i++) {
	// 	for (int j = i + 1; j < n; j++) {
	// 		if (parallel_intersect(segs[i], segs[j])) {
	// 			if (!share(i, j)) {
	// 				unite(i, j);
	// 			}
	// 		}
	// 	}
	// }

	// segs.clear();
	// for (int i = 0; i < n; i++) {
	// 	if (par[i] == i) {
	// 		segs.emplace_back(rep[i]);
	// 	}
	// }

	// n = segs.size();


	int num_components = 0;

	int v = 2 * n;
	int e = n;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (segInter(segs[i].f, segs[i].s, segs[j].f, segs[j].s)) {
				v++;
				e += 2;
				if (!share(i, j)) {
					unite2(i, j);
				}
			}
		}
	}

	// cout << "v: " << v << ", e: " << e << "\n";

	for (int i = 0; i < n; i++) {
		if (par[i] == i) num_components++;
	}

	// v - e + f - (num_components - 1) = 2
	int f = 2 + e - v + (num_components - 1);
	f--;
	cout << f << "\n";


}