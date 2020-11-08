// Source: https://codeforces.com/contest/1444/submission/97383887

struct rollback_disjoint_set{
	vector<int> p;
	vector<pair<int, int>> log;
	rollback_disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : root(p[u]); } // O(log n)
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		log.emplace_back(v, p[v]);
		p[u] += p[v], p[v] = u;
		return true;
	}
	int time(){ return (int)log.size(); }
	void reverse_to(int t = 0){
		for(int i = time(); i --> t; ){
			auto [v, pv] = log[i]; int u = p[v];
			p[u] -= pv, p[v] = pv;
		}
		log.resize(t);
	}
};