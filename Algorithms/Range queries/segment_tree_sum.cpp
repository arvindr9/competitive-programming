#include <bits/stdc++.h>

using namespace std;

void add(int k, int val, int n, vector<int> & tree) {
    k += n;
    while(k >= 1) {
        tree[k] += val;
        k /= 2;
    }
}

int sum(int a, int b, int n, vector<int> tree) {
    int ret = 0;
    a += n;
    b += n;
    while (a <= b) {
        if(a%2 == 1) ret += tree[a++];
        if(b%2 == 0) ret += tree[b--];
        a /= 2;
        b /= 2;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<int> tree(2*n - 1);
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        add(i, arr[i], n, tree);
    }
}