#include <bits/stdc++.h>

using namespace std;

typedef int int2;
#define int long long
#define pi pair<int, int>
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
const int inf = 1e18;


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, A, cf, cm, m;
    cin >> n >> A >> cf >> cm >> m;
    vector<int> a(n);
    vector<pi> b(n);
    vector<int> c(n);
    int numA = 0;
    int mn = inf;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
        if (a[i] == A) numA++;
        mn = min(mn, a[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        c[i] = b[i].s;
    }
    int cur_val = mn * cm + numA * cf; // maybe not necessary
    vector<array<int, 3>> req_mins; // required, min, total length
    req_mins.pb({0LL, a[0], 1LL});
    for (int i = 1; i < n; i++) {
        int new_req = req_mins.back()[0] + (a[i] - a[i - 1]) * req_mins.back()[2];
        int new_min = a[i];
        int new_length = i + 1;
        req_mins.pb({new_req, new_min, new_length});
    }

    int lastA = lower_bound(a.begin(), a.end(), A) - a.begin();
    int total_ops = 0;
    int cur_Afreq = 0;
    for (int i = n - 1; i >= 0; i--) {
        total_ops += (A - a[i]);
        if (a[i] < A) cur_Afreq++;
    }
    int ans = cur_val;
    int optA = lastA;
    
    for (int firstA = 0; firstA <= lastA; firstA++) {
        if (total_ops > m) {
            total_ops -= (A - a[firstA]);
            cur_Afreq--;
            continue;
        }
        if (firstA == 0) {
            // everything can equal A
            ans = cur_val + cur_Afreq * cf + (A - mn) * cm;
            optA = 0;
            break;
        }
        if (firstA > 0) {
            int rem_m = m - total_ops;
            auto it = upper_bound(req_mins.begin(), req_mins.end(), (array<int,3>){rem_m, inf, inf});
            assert(it != req_mins.begin());
            it--;
            auto [req, curmn, len] = *it;
            if (len > firstA) {
                array<int, 3> arr = req_mins[firstA - 1];
                req = arr[0], curmn = arr[1], len = arr[2];
            }
            rem_m -= req;
            int cand = cur_val + cur_Afreq * cf + cm * (curmn - mn) + cm * (rem_m / len);
            if (cand > ans) {
                ans = cand;
                optA = firstA;
            }
        }
        if (firstA < lastA) {
            total_ops -= (A - a[firstA]);
            cur_Afreq--;
        }
    }

    cout << ans << "\n";
    if (optA == 0) {
        for (int i = 0; i < n; i++) {
            cout << A << " ";
        }
        cout << "\n";
    } else {
        int total_ops = 0;
        for (int i = n - 1; i >= optA; i--) {
            total_ops += A - a[i];
        }
        for (int i = optA; i < lastA; i++) {
            a[i] = A;
        }
        int rem_m = m - total_ops;
        auto [req, curmn, len] = * (prev(upper_bound(req_mins.begin(), req_mins.end(), (array<int,3>){rem_m, inf, inf})));
        if (len > optA) {
            array<int, 3> arr = req_mins[optA - 1];
            req = arr[0], curmn = arr[1], len = arr[2];
        }
        for (int i = 0; i < len; i++) {
            a[i] = curmn;
        }
        rem_m -= req;
        int dmin = rem_m / len;
        for (int i = 0; i < len; i++) {
            a[i] += dmin;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[c[i]] = a[i];
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
} 