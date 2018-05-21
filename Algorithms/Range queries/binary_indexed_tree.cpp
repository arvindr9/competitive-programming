#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
int n;

int tree[maxn]

void add(int k, int x) {
    while(k <= n) {
        tree[k] += x;
        k += k&-k;
    }
}

int sum(int k) { //the sum from index l to index r is equal to sum(r, tree) - sum(l-1, tree)
    int ret = 0;
    while(k >= 1) {
        ret += tree[k];
        k -= k&-k;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++) {
        add(i, arr[i]);
    }
    for(int i = 1; i <= n; i++) {
        cout << tree[i] << "\n";
    }
}
