class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        int per = sqrt(n);
        for (int i = 1; i <= per; ++i) {
            for (int j = i * i; j <= n; ++j) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};