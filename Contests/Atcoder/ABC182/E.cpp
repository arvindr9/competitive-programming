// not doing this problem, boring and unuseful for me

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

vector<pi> merge(vector<pi> pairs) {
    sort(pairs.begin(), pairs.end());
    vector<int> res;
    int num_pairs = pairs.size();
    for (int i = 0; i < num_pairs; i++) {
        int l = pairs[i].f;
        int r = pairs[i].s;
        if (!res.empty() and l <= res.back().s) {
            l = min(res.back().f);
            res.pop_back();
        }
        res.eb(l, r);
    }
    return res;
}

const int maxn = 5e5 + 5;

vector<int> hbox[maxn];
vector<int> vbox[maxn];
vector<pi> hseg[maxn];
vector<pi> vseg[maxn];

int h, w, n, m;


int2 main() {
    cin >> h >> w >> n >> m;
}

