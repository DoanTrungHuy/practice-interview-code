class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int dp[1001][101][2];
        memset(dp, 0, sizeof(dp));
        const int n = prices.size();
        for (int i = n - 1; i >= 0; --i) {
            for (int transaction = k; transaction >= 1; --transaction) {
                for (int buy = 0; buy <= 1; ++buy) {
                    if (buy == 1) {
                        dp[i][transaction][buy] = max(
                            -prices[i] + dp[i + 1][transaction][0],
                            dp[i + 1][transaction][1]
                        );
                    }
                    else {
                        dp[i][transaction][buy] = max(
                            prices[i] + dp[i + 1][transaction - 1][1],
                            dp[i + 1][transaction][0]
                        );
                    }
                }
            }
        }
        return dp[0][k][1];
    }
};