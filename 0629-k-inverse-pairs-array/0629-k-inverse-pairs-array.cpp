class Solution {
public:
    int kInversePairs(int n, int k) {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int inv = 0; inv <= min(j, i - 1); inv++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - inv]) % mod;
                }
            }
        }

        return dp[n][k];
    }
};
