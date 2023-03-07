class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int edge = 0;
        
        vector<vector<int>> dp(n, vector<int>(m));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = matrix[i][j] - '0';
                edge = max(edge, dp[i][j]);
            }
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (dp[i][j]) {
                    dp[i][j] += min({
                        dp[i - 1][j], 
                        dp[i][j - 1],
                        dp[i - 1][j - 1]
                    });
                }
                edge = max(edge, dp[i][j]);
            }
        }
        
        return edge*edge;
    }
};