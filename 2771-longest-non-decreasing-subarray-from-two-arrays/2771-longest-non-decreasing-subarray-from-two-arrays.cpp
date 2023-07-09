class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int dp[2][100005] = {};
        
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = 1;
            }
        }
        
        for (int i = 1; i < n; ++i) {
            if (nums1[i - 1] <= nums1[i]) {
                dp[0][i] = max(dp[0][i], dp[0][i - 1] + 1);
            }
            if (nums2[i - 1] <= nums1[i]) {
                dp[0][i] = max(dp[0][i], dp[1][i - 1] + 1);
            }
            if (nums2[i - 1] <= nums2[i]) {
                dp[1][i] = max(dp[1][i], dp[1][i - 1] + 1);
            }
            if (nums1[i - 1] <= nums2[i]) {
                dp[1][i] = max(dp[1][i], dp[0][i - 1] + 1);
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            ans = max({ans, dp[0][i], dp[1][i]});
        }
        
        return ans;
    }
};