class Solution {
public:
    bool isMatch(string s, string p) {
        int n = (int)s.size();
        int m = (int)p.size();
        
        bool dp[n + 1][m + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        
        for (int j = 2; j <= m; ++j) {
            dp[0][j] = dp[0][j - 2] and p[j - 1] == '*';
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == p[j - 1] or p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] or (dp[i - 1][j] and (s[i - 1] == p[j - 2] or p[j - 2] == '.'));
                }
            }
        }
        
        return dp[n][m];
    }
};