#include <bits/stdc++.h>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>

using namespace std;
// using namespace __gnu_pbds;

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;
typedef priority_queue<int, vector<int>, greater<int> > min_heap;

// template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

mt19937_64 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const double PI = 4*atan(1);
const ll INF = 1e18;
const int MX = 100001;

const int maxn = 1e6 + 5;
int t;
int n, k;
vector<string> strings;

map<pair<pi, vector<int>>, int> dp;
int a[35], b[35];

void print_vec(vector<int> & v) {
    for (int i: v) {
        cout << i << " ";
    }
}



int solve(int day, int time, vector<int> state) {
    // cout << "exploring day:  " << day << ", time:  " << time << ", state:  ";
    // print_vec(state);
    // cout << "\n";
    pair<pi, vector<int>> memo_key = mp(mp(day, time), state);

    if (day == n) return dp[memo_key] = 0;
    if (dp.count(mp(mp(day, time), state))) return dp[memo_key];

    int next_day, next_time, next_place, cur_place;
    char cur_char = strings[day][time];
    vector<pair<int, vector<int>>> next_states;
    // calc next_day, next_time, next_states
    next_time = (time + 1) % 3;
    if (next_time == 0) next_day = day + 1;
    else next_day = day;
    if (next_time == 0) {
        cur_place = b[day];
        next_place = 0;
    } else if (next_time == 1) {
        cur_place = 0;
        next_place = a[next_day];
    } else {
        cur_place = a[day];
        next_place = b[next_day];
    }

    //case 1: bring 1 umbrella

    if (state[cur_place] >= 1) {
        vector<int> t2 = state;
        t2[next_place]++;
        t2[cur_place]--;
        next_states.pb(mp(1, t2));
    }

    // case 2: bring 2 umbrellas

    if (state[cur_place] >= 2) {
        vector<int> t2 = state;
        t2[next_place] += 2;
        t2[cur_place] += 2;
        next_states.pb(mp(1, t2));
    }

    //case 3: don't bring umbrella

    if (cur_char == 'S') {
        vector<int> t2 = state;
        next_states.pb(mp(0, t2));
    }

    int res = INF;
    for (pair<int, vector<int>> state: next_states) {
        res = min(res, state.f + solve(next_day, next_time, state.s));
    }
    // cout << "day:  " << day << ", time:  " << time << ", state:  ";
    // print_vec(state);
    // cout << "dp val: " << res << "\n";
    return dp[memo_key] = res;


}


int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);

    cin >> n >> k;
    vector<int> state(k + 1);
    state[0] = 2;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++) {
        string st;
        cin >> st;
        strings.pb(st);
    }
    int ans = solve(0, 0, state);
    cout << ans << "\n";
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/