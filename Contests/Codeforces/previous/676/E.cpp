/*WA on test 20*/

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

const ll p1 = 1e9 + 7;
const ll p2 = 1e9 + 9;

int reduce(int a, int p) {
    return ((a % p) + p) % p;
}

int add(int a, int b, int p) {
    return reduce(a + b, p);
}

int prod(int a, int b, int p) {
    return reduce(a * b, p);
}

int poww1[maxn];
int poww2[maxn];


int to_int(string st) {
    int ans = 0;
    int sz = st.size();
    bool negative = false;
    for (int i = 0; i < sz; i++) {
        if (st[i] == '-') {
            negative = true;
            continue;
        }
        ans *= 10;
        ans += st[i] - '0';
    }
    if (negative) ans = -ans;
    return ans;
}

int2 main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<string> nums(n + 1);
    vector<int> int_nums(n + 1);
    poww1[0] = 1;
    poww2[0] = 1;
    for (int i = 1; i <= n; i++) {
        poww1[i] = prod(poww1[i - 1], k, p1);
        poww2[i] = prod(poww2[i - 1], k, p2);
    }
    // cout << "hi\n";
    int residue1 = 0;
    int residue2 = 0;
    int num_questions = 0;
    for (int i = 0; i <= n; i++) {
        cin >> nums[i];
        if (nums[i] == "?") {
            num_questions++;
            int_nums[i] = INF;
        }
        else {
            int_nums[i] = to_int(nums[i]);
            // cout << "poww1: " << poww1[i] << ", num: " << int_nums[i] << "\n";
            // cout << "prod1: " << prod(int_nums[i], poww1[i], p1) << "\n";
            residue1 = add(residue1, prod(int_nums[i], poww1[i], p1), p1);
            residue2 = add(residue2, prod(int_nums[i], poww2[i], p2), p2);
            // cout << "i= "  << i << ", residue1: " << residue1 << ", residue2: " << residue2 << "\n";
        }
    }
    
    // cout << "num questions: " << num_questions << "\n";
    if (residue1 == 0 and residue2 == 0 and num_questions == 0) {
        cout << "Yes\n";
    } else if (n % 2 == 1 and num_questions > 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

/*
    Potential bugs:
    - Not resetting the arrays properly
    - Out of bounds
*/