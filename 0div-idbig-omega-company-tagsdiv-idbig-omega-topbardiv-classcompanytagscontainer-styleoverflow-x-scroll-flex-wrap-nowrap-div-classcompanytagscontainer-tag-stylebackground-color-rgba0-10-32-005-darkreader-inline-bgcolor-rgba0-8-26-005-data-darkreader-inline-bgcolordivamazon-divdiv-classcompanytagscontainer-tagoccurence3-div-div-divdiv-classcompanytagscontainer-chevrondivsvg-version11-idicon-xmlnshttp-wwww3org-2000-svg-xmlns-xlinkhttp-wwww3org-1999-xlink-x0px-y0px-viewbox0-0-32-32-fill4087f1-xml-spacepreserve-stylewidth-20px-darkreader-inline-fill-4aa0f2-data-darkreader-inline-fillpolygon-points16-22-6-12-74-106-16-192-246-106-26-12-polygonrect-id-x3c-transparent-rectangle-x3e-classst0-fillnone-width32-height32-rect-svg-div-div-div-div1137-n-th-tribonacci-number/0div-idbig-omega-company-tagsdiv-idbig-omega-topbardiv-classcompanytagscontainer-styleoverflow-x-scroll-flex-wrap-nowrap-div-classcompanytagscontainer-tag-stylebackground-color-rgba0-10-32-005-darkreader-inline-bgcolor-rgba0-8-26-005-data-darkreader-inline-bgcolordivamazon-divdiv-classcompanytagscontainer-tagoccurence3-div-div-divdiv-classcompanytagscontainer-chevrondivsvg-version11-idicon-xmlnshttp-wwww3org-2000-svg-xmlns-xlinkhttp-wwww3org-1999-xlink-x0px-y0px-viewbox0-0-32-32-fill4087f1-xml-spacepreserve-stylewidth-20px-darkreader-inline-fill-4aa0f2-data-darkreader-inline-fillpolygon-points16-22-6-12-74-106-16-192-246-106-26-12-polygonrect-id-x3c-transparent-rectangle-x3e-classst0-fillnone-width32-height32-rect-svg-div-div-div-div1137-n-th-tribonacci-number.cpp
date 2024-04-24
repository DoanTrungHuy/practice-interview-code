class Solution {
public:
    int dp[38];
    int T(int n) {
        if (n <= 2 || dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = T(n - 1) + T(n - 2) + T(n - 3);
    }
    int tribonacci(int n) {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        return T(n);
    }
};