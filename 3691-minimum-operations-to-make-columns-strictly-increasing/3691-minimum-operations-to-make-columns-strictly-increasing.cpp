class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        int ans = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[j][i] <= grid[j - 1][i]) {
                    int val = grid[j - 1][i] - grid[j][i] + 1;
                    grid[j][i] += val, ans += val;
                }
            }
        }
        
        return ans;
    }
};
