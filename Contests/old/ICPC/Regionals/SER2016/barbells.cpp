#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxb = 14;
const int maxp = 14;
int b, p;

ll barbells[maxb];
ll plates[maxp];
ll sums[1 << maxp];
set<ll> valid_weights;
vector<ll> ans;

ll compute (int plat) {
    ll res = 0;
    for (int i = 0; i < p; i++) {
        if (plat & (1 << i)) {
            res += plates[i];
        }
    }
    return res;
}

set<ll> possibleSums(ll plat) {
    set<ll> unprocessed;
    for (int i = 0; i < p; i++) {
        if (plat & (1 << i)) {
            unprocessed.insert(plates[i]);
        }
    }
    set<ll> possibles;
    possibles.insert(0LL);
    while (!unprocessed.empty()) {
        set<ll>::iterator it = unprocessed.begin();
        for (auto it2 = possibles.rbegin(); it2 != possibles.rend(); it2++) {
            possibles.insert(*it2 + *it);
        }
        unprocessed.erase(*it);
    }
    return possibles;
}

bool isValid(ll target, ll plat) {
    set<ll> possibles = possibleSums(plat);
    if (possibles.count(target)) return true;
    return false;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    cin >> b >> p;
    for (int i = 0; i < b; i++) {
        cin >> barbells[i];
    }
    for (int i = 0; i < p; i++) {
        cin >> plates[i];
    }
    for (int i = 0; i < (1 << p); i++) {
        sums[i] += compute(i);
    }
    for (int i = 0; i < (1 << p); i++) {
        ll target = sums[i];
        if (target & 1LL) continue;
        if (isValid(target / 2, i)) {
            valid_weights.insert(target);
        }
    }
    for (ll weight: valid_weights) {
        for (int i = 0; i < b; i++) {
            ans.push_back(weight + barbells[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (ll num: ans) {
        cout << num << "\n";
    }
}
