#include <bits/stdc++.h>

using namespace std;

class IncreasingJumps {
    #define pb push_back
    public:
        vector<int> jump(vector<int> frogs) {
            vector<int> ans;
            int n = frogs.size();
            for (int i = 0; i < n; i++) {
                if (frogs[i] > i) {
                    for (int j = 1; j <= frogs[i] - i; j++) {
                        ans.pb(i + 1);
                        ans.pb(-(i + 1));
                    }
                } else {
                    for (int j = 1; j <= i - frogs[i]; j++) {
                        ans.pb(-(i + 1));
                        ans.pb(i + 1);
                    }
                }
            }
            return ans;
        }
};