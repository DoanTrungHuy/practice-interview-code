class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < m; ++j) {
                    grid[i][j] ^= 1;
                }
            }
        }
        
        for (int j = 0; j < m; ++j) {
            int cntOne = 0;
            for (int i = 0; i < n; ++i) {
                cntOne += grid[i][j];
            }
            if (cntOne < n - cntOne) {
                for (int i = 0; i < n; ++i) {
                    grid[i][j] ^= 1;
                }
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int dec = 0, mul = 1;
            for (int j = m - 1; j >= 0; --j) {
                dec += grid[i][j] * mul;
                mul *= 2;
            }
            ans += dec;
        }
        
        return ans;
    }
};