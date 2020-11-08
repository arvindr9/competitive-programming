class Solution {
public:
    #define pi pair<int, int>
    #define mp make_pair
    #define f first
    #define s second

    set<pair<int, pi>> process(2);
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                process[1].pb(mp(matrix[i][j], mp(i, j)));
            }
        }
        for (int i = 1; i < )
    }
};