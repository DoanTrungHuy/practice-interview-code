class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        const int n = nums.size();
        int dp[2][n];
        
        for (int i = 0; i < n; ++i) {
            dp[0][i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[0][i] = max(dp[0][i], dp[0][j] + 1);
                }
            }
        }
        
        for (int i = n - 1; i >= 0; --i) {
            dp[1][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    dp[1][i] = max(dp[1][i], dp[1][j] + 1);
                }
            }
        }
        
        int lis_ = 0;
        
        for (int i = 1; i < n - 1; ++i) {
            if (dp[0][i] > 1 and dp[1][i] > 1) {
                lis_ = max(lis_, dp[0][i] + dp[1][i] - 1);
            }
        }
        
        return n - lis_;
    }
};