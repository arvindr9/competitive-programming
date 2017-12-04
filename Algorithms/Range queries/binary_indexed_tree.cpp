#include <bits/stdc++.h>

using namespace std;

void add(int k, int x, int n, vector<int> &tree) {
    while(k <= n) {
        tree[k] += x;
        k += k&-k;
    }
}

int sum(int k, vector<int> tree) {
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
    vector<int> tree(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++) {
        add(i, arr[i], n, tree);
    }
    for(int i = 1; i <= n; i++) {
        cout << tree[i] << "\n";
    }
}
