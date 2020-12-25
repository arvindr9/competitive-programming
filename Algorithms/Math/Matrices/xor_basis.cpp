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

// https://codeforces.com/contest/1427/submission/102301098

vector<int> basis;
 
bool sim(int a) {
    int A = a;
    for (int b: basis) {
        A = min(A, A ^ b);
    }
    return A;
}
 
void add(int a) {
    int A = a;
    for (int b: basis) {
        if ((A^b) < A) {
            A ^= b;
        }
    }
    if (A) {
        int ind = 0;
        while (ind < (int)basis.size() and basis[ind] > A) ind++;
        basis.insert(basis.begin() + ind, A);
    }
}