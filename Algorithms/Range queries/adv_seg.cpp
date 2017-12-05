#include <bits/stdc++.h>

using namespace std;

int maxPwr(int n) {
    if(pow(2, log2(n)) == n) {
        return n;
    }
    return (pow(2, log2(n)+1));
}
void add(int k, int x, int len, vector<int> &tree) {
    k += len;
    tree[k] += x;
    for(k /= 2; k >= 1; k /= 2) {
        tree[k] += tree[2*k] + tree[2*k+1]; 
    }
}
int sum(int a, int b, int len, vector<int> tree) {
    a += len;
    b += len;
    int sum = 0;
    while(a <= b) {
        if(a % 2 == 1) sum += tree[a++];
        if(b % 2 == 0) sum += tree[b--];
        a /= 2;
        b /= 2;
    }
    return sum;
}
int sum2(int a, int b, int k, int x, int y, vector<int> tree) {
    if (b < x || a > y) return 0;
    if(a <= x && y <= b) return tree[k];
    int d = (x+y)/2;
    return sum2(a, b, 2*k, x, d, tree) + sum2(a, b, 2*k+1, x, d, tree);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int len = maxPwr(n);
    int nodes = 2*len - 1;
    vector<int> arr(len);
    vector<int> sum_tree(nodes + 1);
    for(int i = 0; i < len; i++) {
        cin >> arr[i];
        add(i, arr[i], len, sum_tree);
    }
    
}