
vector<int> as;

ll modpow(ll a, ll power, int mod) {
    if(power == 0) return 1;
    if(power == 1) return a;
    if(power % 2 == 0) return modpow((a * a) % mod, power / 2, mod);
    if(power % 2 == 1) return (a * modpow((a * a) % mod, power / 2, mod)) % mod;
}

void createA() {
    a.push_back(2);
    a.push_back(3);
    a.push_back(5);
    a.push_back(7);
    //possibly up till 37-ish
}

bool isPrime(int n) {
    int d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    bool isPrime = true;
    for(int a: as) {
        ll test = (modpow(a, d, n) + n) % n;
        if (test == 1) continue;
        for (int i = 0; i < s; i++) {
            test = (test * test) % n;
            if (test == n - 1) break;
            if (i == s - 1) isPrime = false;
        }
    }
    return isPrime;
}
