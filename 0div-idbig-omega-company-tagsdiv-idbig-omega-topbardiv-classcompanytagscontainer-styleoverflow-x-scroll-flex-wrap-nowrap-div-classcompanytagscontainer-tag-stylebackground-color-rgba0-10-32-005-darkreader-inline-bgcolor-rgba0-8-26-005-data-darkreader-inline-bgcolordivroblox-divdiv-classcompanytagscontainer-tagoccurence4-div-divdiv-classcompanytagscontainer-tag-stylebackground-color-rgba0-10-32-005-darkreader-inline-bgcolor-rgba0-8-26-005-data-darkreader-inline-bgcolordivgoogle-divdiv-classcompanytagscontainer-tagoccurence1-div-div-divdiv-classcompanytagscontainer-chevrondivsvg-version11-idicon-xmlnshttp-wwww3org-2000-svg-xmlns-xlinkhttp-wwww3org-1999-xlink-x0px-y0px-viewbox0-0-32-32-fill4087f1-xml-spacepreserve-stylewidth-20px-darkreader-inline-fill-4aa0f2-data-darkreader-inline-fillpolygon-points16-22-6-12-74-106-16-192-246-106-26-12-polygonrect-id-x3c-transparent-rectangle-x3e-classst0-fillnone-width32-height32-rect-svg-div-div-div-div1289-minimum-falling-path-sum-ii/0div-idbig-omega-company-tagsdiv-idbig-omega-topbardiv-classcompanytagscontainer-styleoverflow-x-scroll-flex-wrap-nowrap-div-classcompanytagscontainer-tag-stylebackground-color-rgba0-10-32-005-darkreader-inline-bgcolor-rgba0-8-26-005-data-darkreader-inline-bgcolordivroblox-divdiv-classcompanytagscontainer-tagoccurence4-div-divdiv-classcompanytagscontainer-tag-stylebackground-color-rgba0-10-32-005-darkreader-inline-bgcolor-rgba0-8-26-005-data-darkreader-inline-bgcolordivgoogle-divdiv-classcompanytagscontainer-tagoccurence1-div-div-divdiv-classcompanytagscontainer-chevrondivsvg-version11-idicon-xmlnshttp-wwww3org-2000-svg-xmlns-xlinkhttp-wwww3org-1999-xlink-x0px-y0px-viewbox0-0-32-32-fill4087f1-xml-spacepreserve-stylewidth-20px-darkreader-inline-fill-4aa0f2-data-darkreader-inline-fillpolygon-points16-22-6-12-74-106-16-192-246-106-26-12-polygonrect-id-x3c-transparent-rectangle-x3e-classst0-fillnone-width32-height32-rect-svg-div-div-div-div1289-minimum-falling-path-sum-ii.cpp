class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int dummy = grid[i - 1][j];
                grid[i - 1][j] = INT_MAX;
                grid[i][j] += *min_element(grid[i - 1].begin(), grid[i - 1].end());
                grid[i - 1][j] = dummy;
            }
        }
        
        return *min_element(grid[n - 1].begin(), grid[n - 1].end());
    }
};