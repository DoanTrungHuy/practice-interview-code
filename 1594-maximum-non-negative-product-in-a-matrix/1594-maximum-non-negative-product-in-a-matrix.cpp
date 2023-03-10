class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        using ll = long long;
        vector<vector<ll>> dp1(n, vector<ll>(m, 0));
        vector<vector<ll>> dp2 = dp1;
        dp1[0][0] = dp2[0][0] = grid[0][0];
        
        for (int j = 1; j < m; ++j) {
            grid[0][j] *= grid[0][j - 1];
            dp1[0][j] = dp2[0][j] = grid[0][j];
        }
        for (int i = 1; i < n; ++i) {
            grid[i][0] *= grid[i - 1][0];
            dp1[i][0] = dp2[i][0] = grid[i][0];
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (grid[i][j] < 0) {
                    dp2[i][j] = min(dp1[i - 1][j], dp1[i][j - 1]) * grid[i][j];
                    dp1[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]) * grid[i][j];
                }
                else {
                    dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]) * grid[i][j];
                    dp1[i][j] = min(dp1[i - 1][j], dp1[i][j - 1]) * grid[i][j];
                }
            }
        }
        
        const int mod = 1e9 + 7;
        int res = dp2[n - 1][m - 1] % mod;
        return res < 0 ? -1 : res;
    }
};