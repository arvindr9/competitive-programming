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


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    LOOP:while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> freq0(n + 1); // frequency of elements of a[...]
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            freq0[a[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            int f = freq0[i];
            int left = n - f;
            if (f > left + 1) {
                cout << -1 << "\n";
                goto LOOP;
            }
        }
        vector<pi> compressed;
        vector<int> equal_endpts;
        vector<pi> diff_endpts;
        for (int l = 1, r = 1; r <= n; ) {
            while (r < n and a[r] != a[r + 1]) {
                r++;
            }
            compressed.eb(a[l], a[r]);
            r++;
            l = r;
        }
        vector<int> freq(n + 1); // frequency of equal-endpoint elts.
        for (pi p: compressed) {
            if (p.f == p.s) {
                freq[p.f]++;
                equal_endpts.pb(p.f);
            } else {
                diff_endpts.pb(p);
            }
        }
        vector<int> freq2(n + 1); // how often each frequency occurs
        int maxfreq = 0;
        for (int i = 1; i <= n; i++) {
            freq2[freq[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            maxfreq = max(maxfreq, freq[i]);
        }
        // cout << "maxfreq: " << maxfreq << "\n";
        if (maxfreq == 0 or freq2[maxfreq] > 1) { // no equal-endpoint elements, or multiple majority equal-endpoint elements
            cout << (int)compressed.size() - 1LL << "\n";
            goto LOOP;
        }
        int most_frequent = 0;
        for (int i = 1; i <= n; i++) {
            if (freq[i] > freq[most_frequent]) {
                most_frequent = i;
            }
        }
        int num_remaining = (int)equal_endpts.size() - freq[most_frequent];
        // cout << "most_frequent: " << most_frequent << "\n";
        if (freq[most_frequent] <= num_remaining + 1) {
            // majority is not too much
            cout << (int)compressed.size() - 1LL << "\n";
            goto LOOP;
        }
        int amt = freq[most_frequent] - (num_remaining + 1); // try to spend these
        int num_maj = 0;
        int num_nomaj = 0;
        for (pi p: diff_endpts) {
            if (p.f == most_frequent or p.s == most_frequent) {
                num_maj++;
            } else {
                num_nomaj++;
            }
        }
        // pay based on amount of nomaj
        int penalty = max(0LL, amt - num_nomaj);
        // cout << "penalty: " << penalty << "\n";
        cout << (int)compressed.size() - 1LL + penalty << "\n";
    }
}