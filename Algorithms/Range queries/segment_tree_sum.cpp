#include <bits/stdc++.h>

using namespace std;

int nextPwr(int n) {
    return(pow(2, log2(n)) < n ? pow(2, log2(n) + 1) : n);
}

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
    int len = nextPwr(n);
    vector<int> tree(2*len - 1);
    vector<int> arr(len);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        add(i, arr[i], len, tree);
    }
}