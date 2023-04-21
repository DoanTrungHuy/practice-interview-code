class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int m = group.size();
        const int MAXPROFIT = 101, MOD = 1e9 + 7;
        int dp[m + 1][MAXPROFIT + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        
        for (int p = minProfit; p <= MAXPROFIT; ++p) {
            for (int k = 0; k <= n; ++k) {
                dp[m][p][k] = 1;
            }
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (int p = 0; p <= MAXPROFIT; ++p) {
                for (int k = 0; k <= n; ++k) {
                    dp[i][p][k] = dp[i + 1][p][k] % MOD;
                    if (k - group[i] >= 0) {
                        dp[i][p][k] = (dp[i][p][k] + dp[i + 1][min(p + profit[i], MAXPROFIT)][k - group[i]]) % MOD;
                    }
                }
            }
        }
        
        return dp[0][0][n];
    }
};