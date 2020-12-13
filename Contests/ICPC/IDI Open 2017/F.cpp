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

struct range {
    int l, r, freq;
    range(int l, int r, int freq): l(l), r(r), freq(freq) {}
};

int to_int(string st) {
    if ((int)st.size() == 3) {
        return 100;
    }
    if ((int)st.size() == 2) {
        return 10 * (st[0] - '0') + (st[1] - '0');
    }
    return st[0] - '0';
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ll, rr;
    ll = rr = 100;
    int freq = 0;
    vector<range> ranges;
    vector<int> ls(n);
    vector<int> rs(n);
    vector<string> names(n);
    vector<int> range_idx(n);
    fill(range_idx.begin(), range_idx.end(), -1);

    int min_all = 0;
    int max_all = 0;

    for (int i = n - 1; i >= 0; i--) {
        string name;
        string val;
        cin >> name >> val;
        names[i] = name;
        if (val[0] == '?') {
            freq++;
            if (i == 0) {
                ranges.eb(0, rr, freq);
                for (int j = 0; j < freq; j++) {
                    range_idx[i + j] = (int)ranges.size() - 1;
                }
                max_all += rr * freq;
            }
        } else {
            int v = to_int(val);
            min_all += v;
            max_all += v;
            ls[i] = rs[i] = v;
            if (freq > 0) {
                ll = v;
                ranges.eb(ll, rr, freq);
                min_all += ll * freq;
                max_all += rr * freq;
            }
            for (int j = 1; j <= freq; j++) {
                range_idx[i + j] = (int)ranges.size() - 1;
            }
            ll = rr = v;
            freq = 0;
        }
    }


    for (int i = n - 1; i >= 0;) {
        if (~range_idx[i]) {
            range rng = ranges[range_idx[i]];
            int start = i - rng.freq;
            for (int j = 1; j <= rng.freq; j++) {
                int idx = start + j;
                // find max and min
                ls[idx] = max(rng.l, rng.r - (max_all - 100) / j); // decrease of i from rng.r -> will decrease the sum by j * i from max_all. Find largest i such that max_all - j * i >= 100, i.e. i = floor((max_all - 100) / j)
                rs[idx] = min(rng.r, rng.l + (100 - min_all) / (rng.freq - j + 1)); // increase of i from rng.l -> will increase the sum by (freq - j + 1) * i from min_all. Find largest i such that min_all + (freq - j + 1) * i <= 100, i.e. i = floor((100 - min_all) / (freq - j + 1))
            }
            i -= rng.freq;
            continue;
        }
        i--;
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << names[i] << " " << ls[i] << " " << rs[i] << "\n";
    }
} 