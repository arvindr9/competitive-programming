// Source: https://codeforces.com/gym/102896/submission/124817204 (Most likely Yang Liu?)

// Finds solutions to ax^2 + bx + c = 0 mod q, works in log(q) time most of the time

vector<__int128> solve(__int128 q) {
	vector<__int128> ans;
	if (q == 2) {
		for (__int128 i = 0; i < q; ++i)
			if ((a*i*i+b*i+c)%q == 0)
				ans.push_back(i);
			return ans;
	}
	if (a%q == 0) {
		if (b%q == 0) {
			if (c%q == 0) {
				for (__int128 i = 0; i < q; ++i)
					ans.push_back(i);
				return ans;
			}
			return ans;
		}
		ans.push_back((((-c)*exp(b, q-2, q)%q)+q)%q);
		return ans;
	}
	__int128 d = b*b - 4*a*c;
	d = (d%q + q)%q;
	// cout << d << ' ' << q << endl;
	if (d == 0) {
		ans.push_back(((-b*exp(2*a, q-2, q))%q + q)%q);
		return ans;
	}
	if (exp(d, (q-1)/2, q) == q-1)
		return ans;
	__int128 non = -1;
	for (__int128 i = 2; i < q; ++i)
		if (exp(i, (q-1)/2, q) == q-1) {
			non = i;
			break;
		}
	__int128 y = q-1, s = 0;
	while (y%2 == 0) {
		y /= 2;
		s++;
	}
	__int128 mm = s, cc = exp(non, y, q), t = exp(d, y, q), r = exp(d, (y+1)/2, q);
	
	while (t > 1) {
		__int128 tt = t;
		__int128 ind = 0;
		for (__int128 j = 1; j <= mm; ++j) {
			tt = tt*tt%q;
			if (tt == 1) {
				ind = j;
				break;
			}
		}
		__int128 b = cc;
		for (__int128 i = 0; i < mm-ind-1; ++i)
			b = b*b%q;
		mm = ind;
		cc = b*b%q;
		t = t*b%q*b%q;
		r = r*b%q;
	}
	__int128 inv = exp((2*a)%q, q-2, q);
	ans.push_back((((-b+r)*inv%q)+q)%q);
	ans.push_back((((-b-r)*inv%q)+q)%q);
// 	if (q > 3000000)
// 	    cout << (ll)ans[0] << ' ' << (ll)ans[1] << endl;
	return ans;
}