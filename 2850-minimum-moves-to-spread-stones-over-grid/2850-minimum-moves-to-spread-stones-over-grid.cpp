class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        const int n = grid.size();
        
        int cnt_zero = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cnt_zero += grid[i][j] == 0;
            }
        }
        
        if (cnt_zero == 0) {
            return 0;
        }
        
        int ans = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    for (int x = 0; x < n; ++x) {
                        for (int y = 0; y < n; ++y) {
                            if (grid[x][y] > 1) {
                                grid[x][y]--;
                                grid[i][j]++;
                                ans = min(ans, abs(x - i) + abs(y - j) + minimumMoves(grid));
                                grid[x][y]++;
                                grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};