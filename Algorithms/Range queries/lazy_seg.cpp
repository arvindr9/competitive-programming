//Lazy segment tree for addition updates and queries for ranges
#include <bits/stdc++.h>

using namespace std;

const int maxn = 20000;
int tree[2 * maxn + 2];
int lazy[2 * maxn + 2];
int arr[maxn + 1];

int maxP(int num) {
    for(int i = 0; i <= 20; i++) {
        if((1 << i) >= num) {
            return 1 << i;
        }
    }
    return num;
}

void construct_tree(int num) {
    for(int i = 1; i <= num; i++) {
        tree[i + num - 1] = arr[i];
    }
    for(int i = num; i <= 2 * num - 1; i++) {
        int elt = tree[i];
        int index = i;
        while((int)(index / 2) >= 1) {
            tree[index/2] += elt;
            index /= 2;
        }
    }
}
int intersection(int a, int b, int x, int y) {
    return max(0, min(b, y) - max(a, x) + 1);
}

void update_lazy(int a, int b, int mag, int k, int x, int y) {
    if(b < x || a > y) return;
    if(a <= x && y <= b) {lazy[k] += mag; return;}
    int d = (x+y)/2;
    tree[k] += mag * intersection(a, b, x, y);
    update_lazy(a, b, mag, 2*k, x, d);
    update_lazy(a, b, mag, 2*k+1, d+1, y);
}

int sum_lazy(int a, int b, int k, int x, int y) {
    if(b < x || a > y) return 0;
    if(a <= x && y <= b) {return tree[k] + (y - x + 1) * lazy[k];}
    int d = (x+y)/2;
    lazy[2*k] += lazy[k]; lazy[2*k + 1] += lazy[k];
    tree[k] += lazy[k] * intersection(a, b, x, y); lazy[k] = 0;
    return sum_lazy(a, b, 2*k, x, d) + sum_lazy(a, b, 2*k + 1, d+1, y);
}

int main() {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    construct_tree(maxP(n));
    int a, b, mag;
    cin >> a >> b >> mag;
    update_lazy(a, b, mag, 1, 0, maxP(n)-1);
    int a2, b2;
    cin >> a2 >> b2;
    int ans = sum_lazy(a2, b2, 1, 0, maxP(n) - 1);
    cout << ans << "\n";
}