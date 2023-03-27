class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == s[n - j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return n - dp[n][n];
    }
};