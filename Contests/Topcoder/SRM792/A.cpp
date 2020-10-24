#include <bits/stdc++.h>

using namespace std;

class OpenAllHours {

    #define pi pair<int, int>
    #define pb push_back
    #define mp make_pair
    #define f first
    #define s second

    pi process(string st) {
            int h1 = st[0] - '0';
            h1 *= 10;
            h1 += (st[1] - '0');
            int m1 = st[3] - '0';
            m1 *= 10;
            m1 += (st[4] - '0');
            // cout << "result h1: " << h1 << ", result m1:" << m1 << "\n";
            return mp(h1, m1);
    }

    public:

        string verify(int N, vector<string> openingTime, vector<string> closingTime) {
            vector<pi> opens;
            vector<pi> closes;
            vector<pair<pi, int>> all; //+1: add, -1: remove
            for (int i = 0; i < N; i++) {
                string t1 = openingTime[i];
                string t2 = closingTime[i];
                opens.pb(process(t1));
                closes.pb(process(t2));

                all.pb(mp(opens[i], 1));
                all.pb(mp(closes[i], -1));
                pi p3 = mp(opens[i].f + 24, opens[i].s);
                pi p4 = mp(closes[i].f + 24, closes[i].s);
                all.pb(mp(p3, 1));
                all.pb(mp(p4, -1));
            }
            sort(all.begin(), all.end());
            int total_number = 0;
            for (int i = 0; i < N; i++) {
                if (opens[i] > closes[i]) total_number++;
            }
            set<pi> bad_ts;
            for (pair<pi, int> p: all) {
                int h = p.f.f;
                int m = p.f.s;
                int delta = p.s;
                total_number += delta;
                // cout << "h: " << h << ", m: " << m << ", total_number: " << total_number << "\n";
                if (total_number == 0) {
                    bad_ts.insert(mp(h, m));
                } else {
                    bad_ts.erase(mp(h, m));
                }
            }
            // if anything has h between 24 and 47, bad
            string ans = "correct";
            for (pi p: bad_ts) {
                // cout << p.f << " " << p.s << "\n";
                if (p.f >= 24 and p.f <= 47) {
                    ans = "incorrect";
                }
            }
            return ans;
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> openingTime(n);
    for (int i = 0; i < n; i++) {
        cin >> openingTime[i];
    }
    vector<string> closingTime(n);
    for (int i = 0; i < n; i++) {
        cin >> closingTime[i];
    }
    OpenAllHours test = OpenAllHours();
    string ans = test.verify(n, openingTime, closingTime);
    cout << ans << "\n";
}