// AC at https://codeforces.com/contest/1200/submission/109188405

int modpow(int a, int pw, int mod) {
    if (pw == 0) return 1;
    if (pw % 2 == 0) {
        int res = modpow(a, pw / 2, mod);
        return (res * res) % mod;
    }
    return (modpow(a, pw - 1, mod) * a) % mod;
}

int inv(int a, int mod) {
    return modpow(a, mod - 2, mod);
}


struct Hash {
    string st;
    int n;
    int p = 1e9 + 7;
    int x1 = 45678;
    int x2 = 87654;
    vector<int> pre1, pre2;
    vector<int> poww1, powwinv1, poww2, powwinv2;
    int inv1, inv2;

    Hash (string st): st(st), n(st.size()) {
        inv1 = inv(x1, p);
        inv2 = inv(x2, p);
        update();
    }

    void update(vector<int> &v, int num) {
        if (v.empty()) v.pb(1);
        while ((int)v.size() < n) v.pb((v.back() * num) % p);
    }

    void update(vector<int> &v, vector<int> &w) {
        if (v.empty()) v.pb(st[0] - '0');
        while ((int)v.size() < n) {
            int sz = v.size();
            v.pb((v.back() + w[sz] * (st[sz] - '0'))%p);
            if (v.back() < 0) v.back() += p;
        }
    }

    void update() {
        update(poww1, x1);
        update(poww2, x2);
        update(powwinv1, inv1);
        update(powwinv2, inv2);
        update(pre1, poww1);
        update(pre2, poww2);
    }

    void add_string(string &st2) {
        st += st2;
        n = st.size();
        update();
    }

    int get_hash1(int l, int r) {
        int val = pre1[r];
        if (l > 0) val -= pre1[l - 1];
        val = (val * powwinv1[l]) % p;
        if (val < 0) val += p;
        return val;
    }

    int get_hash2(int l, int r) {
        int val = pre2[r];
        if (l > 0) val -= pre2[l - 1];
        val = (val * powwinv2[l]) % p;
        if (val < 0) val += p;
        return val;
    }
};