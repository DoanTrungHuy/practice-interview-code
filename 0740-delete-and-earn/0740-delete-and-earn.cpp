class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int n = 1e4;
        int dp[n + 1] = {};
        for (int num : nums) {
            dp[num] += num;
        }
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + dp[i]);
        }
        return dp[n];
    }
};