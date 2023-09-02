class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp[2], max_len[2];
        max_len[0].resize(n);
        max_len[1].resize(n);
        
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(dp[0].begin(), dp[0].end(), nums[i]);
            if (it == dp[0].end()) {
                dp[0].push_back(nums[i]);
                max_len[0][i] = dp[0].size();
            }
            else {
                *it = nums[i];
                max_len[0][i] = distance(dp[0].begin(), it) + 1;
            }
        }
        
        for (int i = n - 1; i >= 0; --i) {
            auto it = lower_bound(dp[1].begin(), dp[1].end(), nums[i]);
            if (it == dp[1].end()) {
                dp[1].push_back(nums[i]);
                max_len[1][i] = dp[1].size();
            }
            else {
                *it = nums[i];
                max_len[1][i] = distance(dp[1].begin(), it) + 1;
            }
        }
        
        int LIS_ = 0;
        
        for (int i = 1; i < n - 1; ++i) {
            if (max_len[0][i] > 1 and max_len[1][i] > 1) {
                LIS_ = max(LIS_, max_len[0][i] + max_len[1][i] - 1);
            }
        }
        
        return n - LIS_;
    }
};