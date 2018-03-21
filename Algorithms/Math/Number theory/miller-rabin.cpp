
vector<int> as;

ll modpow(ll a, ll power, int mod) {
    if(power == 0) return 1;
    if(power == 1) return a;
    if(power % 2 == 0) return modpow((a * a) % mod, power / 2, mod);
    if(power % 2 == 1) return (a * modpow((a * a) % mod, power / 2, mod)) % mod;
}

void createA() {
    as.push_back(2);
    as.push_back(3);
    as.push_back(5);
    as.push_back(7);
    as.push_back(11);
    as.push_back(13);
    as.push_back(17);
    as.push_back(23);
    as.push_back(29);
    as.push_back(31);
    as.push_back(37);
}

bool isPrime(ll n) {
    if (n % 2 == 0) return false;
    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    bool isPrime = true;
    for(int a: as) {
        ll test = (modpow(a, d, n) + n) % n;
        if (a == n) continue;
        if (test == 1LL) continue;
        if (test == n - 1) continue;
        if (s == 1) {
            isPrime = false;
        }
        for (int i = 1; i < s; i++) {
            test = (test * test) % n;
            if (test == n - 1) break;
            if (i == s - 1) {
                isPrime = false;
            }
        }
    }
    return isPrime;
}

