class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        const int n = nums.size();
        int ans = 1;
        int dp[10003][303];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = abs(nums[i] - nums[j]);
                dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
                ans = max(ans, dp[i][diff]);
            }
            for (int diff = 299; diff >= 0; --diff) {
                dp[i][diff] = max(dp[i][diff], dp[i][diff + 1]);
            }
        }
        
        return ans + 1;
    }
};