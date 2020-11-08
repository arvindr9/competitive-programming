#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    #define pi pair<int, int>
    #define mp make_pair
    #define f first
    #define s second
    
    void dfs(int cand, vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int j, int i0, int j0) {
        int n = heights.size();
        int m = heights[0].size();
        if (i < 0 or j < 0 or i >= n or j >= m or visited[i][j] or abs(heights[i0][j0] - heights[i][j]) > cand) {
            return;
        }
        visited[i][j] = 1;
        for (pi p: {mp(i + 1, j), mp(i, j + 1), mp(i - 1, j), mp(i, j - 1)}) {
            dfs(cand, heights, visited, p.f, p.s, i, j);
        }
    }
    
    
    bool invalid(int cand, vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> visited(n, vector<int>(m));
        dfs(cand, heights, visited, 0, 0, 0, 0);
        return !visited[n - 1][m - 1];
    }
    
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = 0;
        int ln = 20;
        if (!invalid(0, heights)) return 0;
        for (int i = ln; i >= 0; i--) {
            int cand = ans | (1 << i);
            if (invalid(cand, heights)) {
                ans = cand;
            }
        }
        ans++;
        return ans;
    }
};

int main() {
    return 0;
}