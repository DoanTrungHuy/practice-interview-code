class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n, 1);
        int m = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] >= nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    m = max(m, dp[i]);
                }
            }
        }
        return n - m;
    }
};