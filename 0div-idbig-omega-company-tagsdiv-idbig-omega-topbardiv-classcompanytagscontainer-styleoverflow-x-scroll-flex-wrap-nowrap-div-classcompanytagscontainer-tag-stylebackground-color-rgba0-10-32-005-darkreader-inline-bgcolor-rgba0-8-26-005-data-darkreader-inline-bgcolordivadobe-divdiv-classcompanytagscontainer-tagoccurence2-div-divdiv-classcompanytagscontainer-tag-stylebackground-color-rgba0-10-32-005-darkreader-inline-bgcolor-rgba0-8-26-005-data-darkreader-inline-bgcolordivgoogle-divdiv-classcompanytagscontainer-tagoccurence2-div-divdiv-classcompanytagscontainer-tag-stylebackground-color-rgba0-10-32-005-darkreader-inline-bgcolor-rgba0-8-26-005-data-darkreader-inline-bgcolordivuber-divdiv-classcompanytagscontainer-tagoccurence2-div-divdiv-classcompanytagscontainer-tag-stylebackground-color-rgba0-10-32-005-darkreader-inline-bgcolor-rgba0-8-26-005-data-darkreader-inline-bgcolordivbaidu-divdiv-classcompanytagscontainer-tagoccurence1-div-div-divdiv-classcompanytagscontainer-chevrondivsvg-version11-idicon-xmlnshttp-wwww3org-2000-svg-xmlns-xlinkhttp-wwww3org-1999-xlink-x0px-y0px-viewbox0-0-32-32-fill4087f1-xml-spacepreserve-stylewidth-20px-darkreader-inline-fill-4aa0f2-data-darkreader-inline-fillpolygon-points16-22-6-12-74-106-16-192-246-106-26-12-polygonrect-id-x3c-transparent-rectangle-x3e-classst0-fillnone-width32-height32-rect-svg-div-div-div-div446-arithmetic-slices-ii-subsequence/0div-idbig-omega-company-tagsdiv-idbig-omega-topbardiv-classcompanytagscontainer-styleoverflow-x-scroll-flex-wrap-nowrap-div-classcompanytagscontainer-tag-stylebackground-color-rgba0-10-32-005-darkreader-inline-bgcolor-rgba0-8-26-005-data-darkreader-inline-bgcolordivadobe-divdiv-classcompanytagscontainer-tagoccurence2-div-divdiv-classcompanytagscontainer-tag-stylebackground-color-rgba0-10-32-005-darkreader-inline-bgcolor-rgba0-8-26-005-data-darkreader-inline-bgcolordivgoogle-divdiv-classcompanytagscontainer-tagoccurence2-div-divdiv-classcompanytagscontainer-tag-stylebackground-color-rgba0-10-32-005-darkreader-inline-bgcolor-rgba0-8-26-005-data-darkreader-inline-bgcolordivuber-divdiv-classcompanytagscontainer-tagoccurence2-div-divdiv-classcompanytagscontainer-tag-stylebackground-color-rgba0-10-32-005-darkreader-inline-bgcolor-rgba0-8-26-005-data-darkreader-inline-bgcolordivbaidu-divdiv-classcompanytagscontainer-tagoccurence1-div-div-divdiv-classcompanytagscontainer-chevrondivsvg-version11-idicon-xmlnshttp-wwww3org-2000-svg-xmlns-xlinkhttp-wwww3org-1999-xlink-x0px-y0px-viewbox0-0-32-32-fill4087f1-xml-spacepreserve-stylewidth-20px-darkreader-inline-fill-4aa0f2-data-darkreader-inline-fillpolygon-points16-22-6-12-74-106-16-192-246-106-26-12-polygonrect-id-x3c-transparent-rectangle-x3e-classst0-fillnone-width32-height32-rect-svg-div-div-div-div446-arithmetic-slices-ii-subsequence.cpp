class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<map<long long, long long>> dp(n);
        int ans = 0;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];
                ans += dp[j][diff];
                dp[i][diff] += dp[j][diff] + 1;
            }
        }
        
        return ans;
    }
};