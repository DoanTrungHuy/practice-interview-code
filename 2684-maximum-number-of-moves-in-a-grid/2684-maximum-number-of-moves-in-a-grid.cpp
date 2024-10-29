class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        const int DIR[] = {-1, 0, 1};
        int memo[n][m];
        memset(memo, -1, sizeof memo);
        
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if (j == m) {
                return 0;
            }
            if (memo[i][j] != -1) {
                return memo[i][j];
            }
            int ans = 0;
            for (int di : DIR) {
                int ni = i + di;
                if (j + 1 < m && 0 <= ni && ni < n and grid[i][j] < grid[ni][j + 1]) {
                    ans = max(ans, dp(ni, j + 1) + 1);
                }
            }
            return memo[i][j] = ans;
        };
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dp(i, 0));
        }
        
        return ans;
    }
};