// Source: https://www.codechef.com/viewsolution/10766398

vector<Val> gaussianEliminationMod2(vector<Val> v, int B) {
	int n = v.size();
	vector<Val> t(B, 0);
	int used = 0;
	for(int j = B - 1; j >= 0; j --) {
		int i = used;
		while(i < n && (~v[i] >> j & 1)) i ++;
		if(i < n) {
			Val x = v[i];
			swap(v[i], v[used ++]);
			t[j] = x;
			for(i = used; i < n; i ++)
				if(v[i] >> j & 1)
					v[i] ^= x;
		}
	}
	return t;
}