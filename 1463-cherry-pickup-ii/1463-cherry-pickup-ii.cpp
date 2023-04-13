class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        
        int dp[n][m][m];
        memset(dp, 0, sizeof(dp));
        int DIR[3] = {-1, 0, 1};
        
        for (int r = n - 1; r >= 0; --r) {
            for (int c1 = 0; c1 < m; ++c1) {
                for (int c2 = m - 1; c2 >= 0; --c2) {
                    int collectCherry = c1 == c2 
                        ? grid[r][c1] 
                        : grid[r][c1] + grid[r][c2];
                    
                    if (r == 0) {
                        if (!(c1 == 0 and c2 == m - 1)) {
                            continue;
                        }
                    }
                    
                    if (r == n - 1) {
                        dp[r][c1][c2] = collectCherry;
                        continue;
                    }
                    
                    int maxBottom = 0;
                    
                    for (int d1 : DIR) {
                        for (int d2 : DIR) {
                            int nc1 = c1 + d1;
                            int nc2 = c2 + d2;
                            
                            if (0 <= nc1 and nc1 < m and 0 <= nc2 and nc2 < m) {
                                maxBottom = max(maxBottom, dp[r + 1][nc1][nc2]);
                            }
                        }
                    }
                    
                    dp[r][c1][c2] = maxBottom + collectCherry;
                }
            }
        }
        
        return dp[0][0][m - 1];
    }
};