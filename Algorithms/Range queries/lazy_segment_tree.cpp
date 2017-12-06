#include <bits/stdc++.h>

using namespace std;


int maxPwr(int n) {
    int l2 = log2(n);
    if(1<<l2 == n) return n;
    return (1<<(l2+1));
}

void add(int k, int x, int len, vector<int> &tree) {
    k += len;
    tree[k] = x;
    for(k /= 2; k >= 1; k /= 2) {
        tree[k] += x;
    }
}

void add_lazy(int l, int r, int n, int k, int x, int y, vector<int> &tree, vector<int> &lazy) {
    if(r < x || l > y) return;
    if(x >= l && y <= r) {lazy[k] += n; return;}
    int overlap;
    if(x < l && y > r) {overlap = y-x+1;}
    else if (x >= l) overlap = r - x + 1;
    else overlap = r - y + 1;
    tree[k] += n * overlap;
    tree[k] += lazy[k] * (y-x+1);
    lazy[2*k] = lazy[k]; lazy[2*k+1] = lazy[k]; lazy[k] = 0;
    int d = (x+y)/2;
    add_lazy(l, r, n, 2*k, x, d, tree, lazy);
    add_lazy(l, r, n, 2*k+1, d+1, y, tree, lazy);
}
int lazy_sum(int l, int r, int k, int x, int y, vector<int> &tree, vector<int> &lazy) {
    if(r < x || l > y) return 0;
    if(x >= l && y <= r) return tree[k];
    tree[k] += lazy[k] * (y-x+1);
    lazy[2*k] = lazy[k]; lazy[2*k+1] = lazy[k]; lazy[k] = 0;
    int d = (x+y)/2;
    return lazy_sum(l, r, 2*k, x, d, tree, lazy) + lazy_sum(l, r, 2*k+1, d+1, y, tree, lazy); 
}

int main() {
    int n;
    cin >> n;
    int len = maxPwr(n);
    int treelen = 2*len;
    vector<int> arr(len);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> tree(treelen);
    vector<int> lazy(treelen);
    for(int i = 0; i < len; i++) {
        add(i, arr[i], len, tree);
    }
    cout << lazy_sum(3, 5, 1, 0, len-1, tree, lazy) << "\n";


        
}