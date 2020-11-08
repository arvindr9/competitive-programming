// Code for https://codeforces.com/contest/1422/problem/F

#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second


vector<int> small_primes;
vector<int> prime_indices;
int num_primes = 0;
int max_prime;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxval = 2e5 + 5;

int reduce(int a) {
    return (a %= mod) < 0 ? a + mod : a;
}

int add(int a, int b) {
    return reduce(a + b);
}

int prod(int a, int b) {
    return reduce(a * b);
}

int modpow(int a, int pw) {
    if (pw == 0) return 1;
    if (pw % 2 == 0) {
        int res = modpow(a, pw / 2);
        return prod(res, res);
    }
    return prod(modpow(a, pw - 1), a);
}

pair<map<int, int>, int> prime_fact(int n) {
    pair<map<int, int>, int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res.f[i]++;
            n /= i;
        }
    }
    if (n <= max_prime) {
        res.s = 1;
        if (n > 1) res.f[n]++;
    } else {
        res.s = n;
    }
    return res;
}

struct small_node {
    vector<int> powers;
    small_node() {
        powers.resize(num_primes);
    }
    small_node(vector<int> &powers) {
        this->powers = powers;
    }
    small_node(map<int, int> &factors) {
        powers.resize(num_primes);
        for (pi p: factors) {
            powers[prime_indices[p.f]] += p.s;
        }
    }
    friend small_node operator+(const small_node &a, const small_node &b) {
        small_node c;
        for (int i = 0; i < num_primes; i++) {
            c.powers[i] = max(a.powers[i], b.powers[i]);
        }
        return c;
    }
};

struct segtree {
    vector<small_node> t;
    int n;

    segtree(vector<small_node> &a) {
        n = (int)a.size() - 1;
        t.resize(4 * n + 5);
        build(1, 1, n, a);
    }

    void build(int v, int tl, int tr, vector<small_node> &a) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(2 * v, tl, tm, a);
            build(2 * v + 1, tm + 1, tr, a);
            t[v] = t[2 * v] + t[2 * v + 1];
        }
    }

    small_node query_lcm(int v, int tl, int tr, int l, int r) {
        small_node res;
        if (l > r) return res;
        if (l == tl and r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return query_lcm(2 * v, tl, tm, l, min(tm, r)) + query_lcm(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }  

    void build(vector<small_node> &a) {
        build(1, 1, n, a);
    }

    int query_lcm(int l, int r) {
        small_node lc = query_lcm(1, 1, n, l, r);
        int res = 1;
        for (int i = 0; i < (int)lc.powers.size(); i++) {
            res = prod(res, modpow(small_primes[i], lc.powers[i]));
        }
        return res;
    }

};

int n;


struct big_node {
    big_node *l, *r;
    int val;
    big_node(): l(nullptr), r(nullptr), val(val) {}
    big_node(int val) : l(nullptr), r(nullptr), val(val) {}
    big_node(big_node *l, big_node *r): l(l), r(r), val(1) {
        if (l) val = prod(val, l-> val);
        if (r) val = prod(val, r-> val);
    }

};

big_node* build(int tl, int tr, vector<int> &a) {
    if (tl == tr) {
        return new big_node(a[tl]);
    }
    int tm = (tl + tr) / 2;
    return new big_node(build(tl, tm, a), build(tm + 1, tr, a));
}

big_node* upd(big_node* v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        return new big_node(val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return new big_node(upd(v->l, tl, tm, pos, val), v->r);
        } else {
            return new big_node(v->l, upd(v->r, tm + 1, tr, pos, val));
        }
    }
}

int query_prod(big_node* v, int tl, int tr, int l, int r) {
    if (l > r) return 1;
    if (l == tl and r == tr) return v->val;
    int tm = (tl + tr) / 2;
    return prod(query_prod(v->l, tl, tm, l, min(tm, r)), query_prod(v->r, tm + 1, tr, max(l, tm + 1), r));
}

big_node* upd(big_node* v, int pos, int val) {
    return upd(v, 1, n, pos, val);
}

int query_prod(big_node* v, int l, int r) {
    return query_prod(v, 1, n, l, r);
}
big_node* build(vector<int> &a) {
    return build(1, n, a);
}

void init() {
    
    max_prime = sqrt(2e5);
    vector<int> isprime(max_prime + 1);
    prime_indices.resize(max_prime + 1);
    for (int i = 2; i <= max_prime; i++) {
        isprime[i] = 1;
    }
    for (int i = 2; i <= max_prime; i++) {
        if (isprime[i]) {
            for (int j = 2 * i; j <= max_prime; j += i) {
                isprime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= max_prime; i++) {
        if (isprime[i]) {
            small_primes.push_back(i);
            prime_indices[i] = (int)small_primes.size() - 1;
        }
    }
    num_primes = small_primes.size();
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    // test_pseg();
    cin >> n;
    vector<int> a(n + 1);
    vector<small_node> seg_input(n + 1);
    vector<int> big_factors(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pair<map<int, int>, int> factors = prime_fact(a[i]);
        seg_input[i] = small_node(factors.f);
        big_factors[i] = factors.s;
    }

    segtree tree = segtree(seg_input);
    vector<int> initial(n + 1);
    fill(initial.begin(), initial.end(), 1);
    big_node* initial_tree = build(initial);
    vector<big_node*> psegs = {initial_tree};

    //create psegtree
    vector<int> last_pos(maxval);
    fill(last_pos.begin(), last_pos.end(), -1);
    for (int i = 1; i <= n; i++) {
        big_node* cur_root = psegs[i - 1];
        int fac = big_factors[i];
        if (~last_pos[fac]) {
            int p0 = last_pos[fac];
            cur_root = upd(cur_root, p0, 1);
        }
        last_pos[fac] = i;
        cur_root = upd(cur_root, i, fac);
        psegs.pb(cur_root);
    }
    

    //process online queries

    int q;
    cin >> q;

    for (int i = 1, l = 0, r = 0, ans = 0; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        l = (ans + x) % n + 1;
        r = (ans + y) % n + 1;
        if (l > r) swap(l, r);
        int tree_res = tree.query_lcm(l, r);
        int pseg_res = query_prod(psegs[r], l, r);
        ans = prod(tree_res, pseg_res);
        cout << ans << "\n";
    }

}

