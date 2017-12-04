#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int W = 0;
    vector<int> w;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (auto i: w) {
        W += i;
    }
    vector<int> possible(W);
    possible[0] = true;
    for(int k = 1; k <= n; k++) {
        for(int x = W; x >= 0; x--) {
            if(possible[x]) possible[x+w[k]] = true;
        }
    }
}
