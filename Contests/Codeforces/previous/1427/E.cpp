// 1427 E: Xum

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
const int inf = 1e18;

// based on summitwei's solution

vector<string> calcs;
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
            calcs.pb(to_string(A) + " ^ " + to_string(b));
            A ^= b;
        }
    }
    if (A) {
        int ind = 0;
        while (ind < (int)basis.size() and basis[ind] > A) ind++;
        basis.insert(basis.begin() + ind, A);
    }
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    

    int x;
    cin >> x;
    add(x);

    while (true) {
        uniform_int_distribution<> distrib1(0, basis.size() - 1);
        int a = distrib1(rng);
        int b = distrib1(rng);
        if (basis[a] > inf or basis[b] > inf) continue;
        int x = basis[a] + basis[b];
        if (sim(x)) {
            calcs.pb(to_string(basis[a]) + " + " + to_string(basis[b]));
            add(x);
        }
        if (basis[basis.size() - 1] == 1) break;
    }
    cout << calcs.size() << "\n";
    for (string st: calcs) {
        cout << st << "\n";
    }
}