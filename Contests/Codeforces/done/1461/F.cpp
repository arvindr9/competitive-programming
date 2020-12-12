#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long

#define pi pair<int, int>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

bool pluss = false;
bool minuss = false;
bool times = false;
vector<char> all_ops;
const int maxn = 1e5 + 5;
int dp[maxn], prv[maxn];
int elts[maxn];

void process(char c) {
    if (c == '-') minuss = true;
    else if (c == '*') times = true;
    else pluss = true;
}

vector<char> solve(int l, int r) {
    vector<char> ops;
    // assuming * and +

    int nn = (r - l + 1);
    int prod = 1;
    bool all_times = false;
    vector<int> prods;

    for (int i = l; i <= r; i++) {
        prod *= elts[i];
        prods.pb(prod);
        if (prod >= 2 * nn) {
            all_times = true;
            break;
        }
    }

    function<int(int, int)> query_prod = [&](int ll, int rr) {
        int den;
        if (ll == l) den = 1;
        else den = prods[ll - l - 1];
        int num;
        if (rr == l) num = 1;
        else num = prods[rr - l];
        return num / den;
    };

    if (all_times) {
        for (int i = l; i < r; i++) {
            ops.pb('*');
        }
        return ops;
    }

    // dp[i]: max cost for the prefix [l...i]

    dp[l] = elts[l];
    dp[l - 1] = 0; // supposing l is the beginning
    prv[l] = l - 1;
    vector<int> important_states = {l};
    for (int i = l + 1; i <= r; i++) {
        if (elts[i] == 1) {
            dp[i] = dp[i - 1] + 1; //add plus sign
            prv[i] = i - 1;
        } else {
            // this will run at most log(2n) times, so important_states will have size at most log(2n)
            important_states.pb(i);
            for (int j: important_states) {
                int cand = dp[j - 1] + query_prod(j, i);
                if (cand > dp[i]) {
                    prv[i] = j - 1;
                    dp[i] = cand;
                }
            }
        }
    }

    // now backtrack to generate ops
    int idx = r;
    while (idx > l) {
        if (prv[idx] == idx - 1) ops.pb('+');
        else {
            for (int j = idx - 1; j >= max(l, prv[idx] + 1); j--) {
                ops.pb('*');
            }
            if (prv[idx] >= l) ops.pb('+');
        }
        idx = prv[idx];
    }
    reverse(ops.begin(), ops.end());

    return ops;
}

int n;

void print() {
    for (int i = 1; i <= n; i++) {
        cout << elts[i];
        if (i < n) {
            cout << all_ops[i - 1];
        }
    }
    cout << "\n";
}

pi computelr(int l, int r) {
    while (elts[l] <= 1 and l < r) l++;
    while (elts[r] <= 1 and r > l) r--;
    return mp(l, r);
}

void addops(int lb, int ub, int l, int r, vector<char> &ops) {
    for (int i = lb; i < l; i++) all_ops.pb('+');
    for (char op: ops) all_ops.pb(op);
    for (int i = r; i < ub; i++) all_ops.pb('+');
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> elts[i];
    }
    string ops;
    cin >> ops;
    int num_ops = ops.size();
    for (int i = 0; i < num_ops; i++) {
        process(ops[i]);
    }
    string ans;
    if (num_ops == 1) {
        for (int i = 1; i < n; i++) {
            all_ops.pb(ops[0]);
        }
        print();
        return 0;
    }
    if (pluss and times) {
        // interersting part of problem
        vector<int> zeros;
        for (int i = 1; i <= n; i++) {
            if (elts[i] == 0) zeros.pb(i);
        }
        int num_zeros = zeros.size();
        zeros.pb(n + 1);
        if (num_zeros) {
            // process to the left of first zero
            if (zeros[0] > 1) {
                vector<char> ops;
                auto [l, r] = computelr(1, zeros[0] - 1);
                if (l < r) ops = solve(l, r);
                addops(1, zeros[0], l, r, ops);
            }

            // process to the right of each of the zeros
            for (int i = 0; i < num_zeros; i++) {
                if (zeros[i] == n) continue;
                else if (zeros[i] + 1 == zeros[i + 1]) all_ops.pb('+');
                else {
                    all_ops.pb('+');
                    vector<char> ops;
                    auto [l, r] = computelr(zeros[i] + 1, zeros[i + 1] - 1);
                    if (l < r) ops = solve(l, r);
                    addops(zeros[i] + 1, min(n, zeros[i + 1]), l, r, ops);
                }
            }
        } else {
            // ignore leading and trailing ones
            auto [l, r] = computelr(1, n);
            // cout << "l: " << l << ", r: " << r << "\n";
            vector<char> ops;
            if (l < r) ops = solve(l, r);
            addops(1, n, l, r, ops);
        }
        print();
        return 0;
    }

    if (pluss and minuss) {
        for (int i = 1; i < n; i++) {
            all_ops.pb('+');
        }
        print();
        return 0;
    }

    //minus and times

    for (int i = 1; i < n; i++) {
        if (elts[i + 1] == 0) all_ops.pb('-');
        else all_ops.pb('*');
    }
    print();
 
}