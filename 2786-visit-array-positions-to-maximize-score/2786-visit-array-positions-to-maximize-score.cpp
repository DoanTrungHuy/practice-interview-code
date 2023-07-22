class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        long long dp[2][n];
        
        dp[0][0] = dp[1][0] = -1e18;
        
        if (nums[0] % 2 == 0) {
            dp[0][0] = nums[0];
        }
        else {
            dp[1][0] = nums[0];
        }
        
        long long ans = nums[0];
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                dp[0][i] = max({
                    dp[0][i - 1],
                    dp[0][i - 1] + nums[i],
                    dp[1][i - 1] + nums[i] - x
                });
                dp[1][i] = max({
                    dp[1][i - 1],
                    dp[0][i - 1] + nums[i] - x
                });
            }
            else {
                dp[0][i] = max({
                    dp[0][i - 1],
                    dp[1][i - 1] + nums[i] - x
                });
                dp[1][i] = max({
                    dp[1][i - 1],
                    dp[1][i - 1] + nums[i],
                    dp[0][i - 1] + nums[i] - x
                });
            }
            
            ans = max(dp[0][i], dp[1][i]);
        }
        
        return ans;
    }
};