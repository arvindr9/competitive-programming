#include <bits/stdc++.h>

using namespace std;


template<typename T>
struct Z_p{
	using Type = typename decay<decltype(T::value)>::type;
	static vector<Type> mod_inv; 
	constexpr Z_p(): value(){ }
	template<typename U> Z_p(const U &x){ value = normalize(x); }
	template<typename U> static Type normalize(const U &x){
		Type v;
		if(-mod() <= x && x < mod()) v = static_cast<Type>(x);
		else v = static_cast<Type>(x % mod());
		if(v < 0) v += mod();
		return v;
	}
	const Type& operator()() const{ return value; }
	template<typename U> explicit operator U() const{ return static_cast<U>(value); }
	constexpr static Type mod(){ return T::value; }
	Z_p &operator+=(const Z_p &otr){ if((value += otr.value) >= mod()) value -= mod(); return *this; }
	Z_p &operator-=(const Z_p &otr){ if((value -= otr.value) < 0) value += mod(); return *this; }
	template<typename U> Z_p &operator+=(const U &otr){ return *this += Z_p(otr); }
	template<typename U> Z_p &operator-=(const U &otr){ return *this -= Z_p(otr); }
	Z_p &operator++(){ return *this += 1; }
	Z_p &operator--(){ return *this -= 1; }
	Z_p operator++(int){ Z_p result(*this); *this += 1; return result; }
	Z_p operator--(int){ Z_p result(*this); *this -= 1; return result; }
	Z_p operator-() const{ return Z_p(-value); }
	template<typename U = T>
	typename enable_if<is_same<typename Z_p<U>::Type, int>::value, Z_p>::type &operator*=(const Z_p& rhs){
		#ifdef _WIN32
		uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
		uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
		asm(
			"divl %4; \n\t"
			: "=a" (d), "=d" (m)
			: "d" (xh), "a" (xl), "r" (mod())
		);
		value = m;
		#else
		value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
		#endif
		return *this;
	}
	template<typename U = T>
	typename enable_if<is_same<typename Z_p<U>::Type, int64_t>::value, Z_p>::type &operator*=(const Z_p &rhs){
		int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
		value = normalize(value * rhs.value - q * mod());
		return *this;
	}
	template<typename U = T>
	typename enable_if<!is_integral<typename Z_p<U>::Type>::value, Z_p>::type &operator*=(const Z_p &rhs){
		value = normalize(value * rhs.value);
		return *this;
	}
	Z_p operator^(long long e) const{
		Z_p b = *this, res = 1;
		if(e < 0) b = 1 / b, e = -e;
		for(; e; b *= b, e >>= 1) if(e & 1) res *= b;
		return res;
	}
	Z_p &operator^=(const long long &e){ return *this = *this ^ e; }
	Z_p &operator/=(const Z_p &otr){
		Type a = otr.value, m = mod(), u = 0, v = 1;
		if(a < int(mod_inv.size())) return *this *= mod_inv[a];
		while(a){
			Type t = m / a;
			m -= t * a; swap(a, m);
			u -= t * v; swap(u, v);
		}
		assert(m == 1);
		return *this *= u;
	}
	template<typename U> friend const Z_p<U> &abs(const Z_p<U> &v){ return v; }
	Type value;
};
template<typename T> bool operator==(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value == rhs.value; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(const Z_p<T>& lhs, U rhs){ return lhs == Z_p<T>(rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator==(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) == rhs; }
template<typename T> bool operator!=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(const Z_p<T> &lhs, U rhs){ return !(lhs == rhs); }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> bool operator!=(U lhs, const Z_p<T> &rhs){ return !(lhs == rhs); }
template<typename T> bool operator<(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value < rhs.value; }
template<typename T> bool operator>(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value > rhs.value; }
template<typename T> bool operator<=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value <= rhs.value; }
template<typename T> bool operator>=(const Z_p<T> &lhs, const Z_p<T> &rhs){ return lhs.value >= rhs.value; }
template<typename T> Z_p<T> operator+(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(const Z_p<T> &lhs, U rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator+(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) += rhs; }
template<typename T> Z_p<T> operator-(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator-(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) -= rhs; }
template<typename T> Z_p<T> operator*(const Z_p<T> &lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(const Z_p<T>& lhs, U rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator*(U lhs, const Z_p<T> &rhs){ return Z_p<T>(lhs) *= rhs; }
template<typename T> Z_p<T> operator/(const Z_p<T> &lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(const Z_p<T>& lhs, U rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T, typename U, typename enable_if<is_integral<U>::value>::type* = nullptr> Z_p<T> operator/(U lhs, const Z_p<T> &rhs) { return Z_p<T>(lhs) /= rhs; }
template<typename T> istream &operator>>(istream &in, Z_p<T> &number){
	typename common_type<typename Z_p<T>::Type, int64_t>::type x;
	in >> x;
	number.value = Z_p<T>::normalize(x);
	return in;
}
template<typename T> ostream &operator<<(ostream &out, const Z_p<T> &number){ return out << number(); }
 
/*
using ModType = int;
struct VarMod{ static ModType value; };
ModType VarMod::value;
ModType &mod = VarMod::value;
using Zp = Z_p<VarMod>;
*/
 
constexpr int mod = (119 << 23) + 1;
using Zp = Z_p<integral_constant<decay<decltype(mod)>::type, mod>>;
 
template<typename T> vector<typename Z_p<T>::Type> Z_p<T>::mod_inv;
template<typename T = integral_constant<decay<decltype(mod)>::type, mod>>
void precalc_inverse(size_t SZ){
	auto &inv = Z_p<T>::mod_inv;
	if(inv.empty()) inv.assign(2, 1);
	for(; inv.size() <= SZ; ) inv.push_back((mod - 1LL * mod / (int)inv.size() * inv[mod % (int)inv.size()] % mod) % mod);
}
 
// Requires modular
template<class T, int root = 15311432, int root_pw = 1 << 23, int inv_root = 469870224>
void number_theoric_transform(vector<T> &a, const bool invert = false){
	int n = (int)a.size();
	for(int i = 1, j = 0; i < n; ++ i){
		int bit = n >> 1;
		for(; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		if(i < j) swap(a[i], a[j]);
	}
	for(int len = 1; len < n; len <<= 1){
		T wlen = invert ? inv_root : root;
		for(int i = len << 1; i < root_pw; i <<= 1) wlen *= wlen;
		for(int i = 0; i < n; i += len << 1){
			T w = 1;
			for(int j = 0; j < len; ++ j, w *= wlen){
				T u = a[i + j], v = a[i + j + len] * w;
				a[i + j] = u + v, a[i + j + len] = u - v;
			}
		}
	}
	if(invert){
		T inv_n = T(1) / n;
		for(auto &x: a) x *= inv_n;
	}
} // NTTmod: 998244353(2^23*7*17,3),754974721(2^24*3^2*5,11),469762049(2^26*7,3),167772161(2^25*5,3)
template<class T>
vector<T> convolute(vector<T> p, vector<T> q){
	if(min(p.size(), q.size()) < 60){
		vector<T> res((int)p.size() + (int)q.size() - 1);
		for(size_t i = 0; i < p.size(); ++ i) for(size_t j = 0; j < q.size(); ++ j) res[i + j] += p[i] * q[j];
		return res;
	}
	int m = max((int)p.size() + (int)q.size() - 1, 1), n = m;
	if(__builtin_popcount(n) != 1) n = 1 << __lg(n) + 1;
	p.resize(n), q.resize(n);
	number_theoric_transform(p), number_theoric_transform(q);
	for(int i = 0; i < n; ++ i) p[i] *= q[i];
	number_theoric_transform(p, true);
	p.resize(m);
	return p;
}

template<class T>
vector<T> add(vector<T> p, vector<T> q) {
    vector<T> res;
    res.resize(max(p.size(), q.size()));
    for (int i = 0; i < (int)p.size(); i++) {
        res[i] += p[i];
    }
    for (int i = 0; i < (int)q.size(); i++) {
        res[i] += q[i];
    }
    return res;
}

void print(vector<Zp> &v) {
    cout << (int)v.size() - 1 << "\n";
    for (auto elt: v) {
        if (elt != (Zp)1 and elt != (Zp)0) {
            cout << -1 << " ";
        } else {
            cout << elt << " ";
        }
    }
    cout << "\n";
}


typedef int int2;
#define int long long
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
const int inf = 1e18;

// struct poly {
//     vector<int> elts;
//     int n;
//     poly() {}
//     poly(int _n) {
//         elts.resize(n + 1);
//         n = _n;
//     }
//     poly(const poly &p) {
//         n = p.n;
//         elts.resize(n + 1);
//         for (int i = 0; i <= n; i++) {
//             elts[i] = p.elts[i];
//         }
//     }
//     poly(vector<int> v) {
//         elts = v;
//         n = (int)v.size() - 1;
//         // cout << "n: " << n << "\n";
//     }
//     friend poly operator *(const poly &p1, const poly & p2) {
//         int n1 = p1.n;
//         int n2 = p2.n;
//         int n3 = max(n1, n2) + 1;
//         poly p3(n3);
//         cout << "n1: " << n1 << ", n2: " << n2 << ", n3: " << n3 << "\n";
//         // for (int i = 0; i <= n1; i++) {
//         //     for (int j = 0; j <= n2; j++) {
//         //         p3.elts[i + j] += p1.elts[i] * p2.elts[j];
//         //     }
//         // }
//         return p3;
//     }

//     friend poly operator +(const poly &p1, const poly &p2) {
//         int n1 = p1.n;
//         int n2 = p2.n;
//         int n3 = max(n1, n2);
//         cout << "p1 elts size: " << p1.elts.size() << ", n1: " << n1 << "\n";
//         cout << "n2: " << n2 << "\n";
//         // assert(n1 == (int)p1.elts.size() - 1);
//         // assert(n2 == (int)p2.elts.size() - 1);
//         // poly p3;
//         // for (int i = 0; i <= n3; i++) {
//         //     if (i <= n1) p3.elts[i] += p1.elts[i];
//         //     if (i <= n2) p3.elts[i] += p2.elts[i];
//         // }
//         return p1;
//     }
// };

// poly copy(poly p) {
//     poly res;
//     res.n = p.n;
//     res.elts.resize(res.n + 1);
//     for (int i = 0; i <= res.n; i++) {
//         res.elts[i] = p.elts[i];
//     }
//     return res;
// }

// void print(poly & p) {
//     cout << p.n << "\n";
//     for (int i = p.n; i >= 0; i--) {
//         cout << p.elts[i] << " ";
//     }
//     cout << "\n";
// }

// #define vi vector<int>
// #define sz(x) (int)x.size()

// Source: Aeren (https://codeforces.com/contest/1450/submission/100572134)


bool satisfy(vector<Zp> v) {
    for (Zp elt: v) {
        int intelt = (int)elt;
        if (intelt > 1) intelt -= mod;
        if (intelt < -1 or intelt > 1) {
            return false;
        }
    }
    return true;
}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Zp> v1 = {-1};
    vector<Zp> v2 = {0, 1};
    vector<Zp> x = {0, 1};
    vector<Zp> base2 = {0, 1};
    vector<Zp> base1 = {1};
    vector<Zp> n1 = {-1};
    // poly zerop = poly(zero);
    for (int i = 2; i <= n; i++) {
        vector<Zp> inter = convolute(v2, x);
        vector<Zp> v3 = add(inter, v1);
        if (!satisfy(v3)) {
            v3 = add(inter, convolute(n1, v1));
        }
        v1 = v2;
        v2 = v3;
    }
    if (n == 1) {
        print(base2);
        print(base1);
        return 0;
    }
    print(v2);
    print(v1);
} 