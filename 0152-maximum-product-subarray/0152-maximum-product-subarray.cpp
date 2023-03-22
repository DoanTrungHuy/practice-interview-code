class Solution {
public:
    int maxProduct(vector<int>& nums) {        
        int n = nums.size();
        int dp[n][2];
        dp[0][0] = dp[0][1] = nums[0];
        int ans = nums[0];
        
        for (int i = 1; i < n; ++i) {
            for (int state = 0; state <= 1; ++state) {
                ans = max({ans, nums[i], nums[i] * dp[i - 1][state]});
            }
            dp[i][0] = max({nums[i], nums[i] * dp[i - 1][1], nums[i] * dp[i - 1][0]});
            dp[i][1] = min({nums[i], nums[i] * dp[i - 1][1], nums[i] * dp[i - 1][0]});
        }
        
        return ans;
    }
};