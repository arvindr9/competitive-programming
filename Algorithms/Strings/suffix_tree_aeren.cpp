// Adjacency_Type: array<int, X> or map<Char_Type, int> where X is the size of the alphabet
template<class Char_Type, class Adjacency_Type>
struct suffix_tree{
	int n = 0; // length of the underlying string
	vector<Char_Type> s; // underlying string
	// Begin States
	// The position of the label of the parent edge in the string, temporary length of the parent edge, suffix link, parent vertex
	vector<int> pos{0}, len{numeric_limits<int>::max()}, link{0}, pv{0};
	vector<Adjacency_Type> next{{}};
	// End States
	int new_state(int p, int l = numeric_limits<int>::max()){
		pos.push_back(p);
		len.push_back(l);
		link.push_back(-1);
		pv.push_back(-1);
		next.push_back({});
		return (int)pos.size() - 1;
	}
	int u_last = 0, extra = 0;
	void extend(Char_Type c){
		s.push_back(c), ++ n, ++ extra;
		for(auto last = 0; extra; ){
			while(extra > len[next[u_last][s[n - extra]]]) u_last = next[u_last][s[n - extra]], extra -= len[u_last];
			Char_Type edge = s[n - extra];
			int u = next[u_last][edge];
			Char_Type t = s[pos[u] + extra - 1];
			if(!u){
				u = new_state(n - extra);
				link[last] = u_last;
				last = 0;
			}
			else if(t == c){
				link[last] = u_last;
				return;
			}
			else{
				int v = new_state(pos[u], extra - 1);
				next[v][c] = new_state(n - 1), pv[next[v][c]] = v;
				next[v][t] = u, pv[u] = v;
				pos[u] += extra - 1, len[u] -= extra - 1;
				u = last = link[last] = v;
			}
			next[u_last][edge] = u, pv[u] = u_last;
			if(u_last) u_last = link[u_last];
			else -- extra;
		}
	}
	void extend(const vector<Char_Type> &s){
		for(auto c: s) extend(c);
	}
	int size() const{ // # of states
		return (int)pos.size();
	}
	int length(int u) const{ // actual length of the parent edge
		return u ? min(len[u], (int)s.size() - pos[u]) : 0;
	}
};