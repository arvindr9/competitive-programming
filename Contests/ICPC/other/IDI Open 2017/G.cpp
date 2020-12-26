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

struct state {
    int x, y, time;
    string type;
    state(int x, int y, int time, string type): x(x), y(y), time(time), type(type) {}
    bool operator <(const state &other) const {
        return time < other.time;
    }
};
int n;

bool valid(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < n;
}

// observation: energy will never go above 200
const int maxe = 201;
const int maxs = 501;

int dp[maxs][maxe];

int dist(state s1, state s2) {
    return abs(s1.x - s2.x) + abs(s1.y - s2.y);
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<state> states;
    int e, sx, sy, c;
    cin >> n >> e >> sx >> sy >> c;
    states.eb(sx, sy, 0, "start");
    for (int i = 1; i <= c; i++) {
        int x, y, ct;
        cin >> x >> y >> ct;
        states.eb(x, y, ct, "can");
        for (pi p: {mp(x - 1, y), mp(x + 1, y), mp(x, y - 1), mp(x, y + 1)}) if(valid(p.f, p.s)) states.eb(p.f, p.s, ct, "energy");
    }

    sort(states.begin(), states.end());

    int num_states = states.size();
    for (int i = num_states - 1; i >= 0; i--) {
        state st = states[i];
        int can_offset = 0;
        if (st.type == "can") can_offset = 1;
        int energy_offset = 0;
        if (st.type == "energy") energy_offset = 1;
        for (int energy = maxe - 1; energy >= 0; energy--) {
            dp[i][energy] = can_offset;
            for (int j = i + 1; j < num_states; j++) {
                int cost = dist(states[j], st);
                if (energy + energy_offset - cost >= maxe) continue;
                if (cost > states[j].time - st.time) continue;
                if (cost <= energy + energy_offset) {
                    dp[i][energy] = max(dp[i][energy], can_offset + dp[j][energy + energy_offset - cost]);
                }
            }
        }
    }

    cout << dp[0][e] << "\n";
} 