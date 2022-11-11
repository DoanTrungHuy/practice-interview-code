class Solution {
public:
    int dp[22][100005];
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            dp[0][i + 1] = nums[i]; 
        }
        int m = log2(n) + 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n - (1 << i) + 1; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
            }
        }
        vector<int> ans;
        for (int j = 1; j <= n - k + 1; ++j) {
            int l = j;
            int r = j + k - 1;
            int i = log2(r - l + 1);
            ans.push_back(max(dp[i][l], dp[i][r - (1 << i) + 1]));
        }
        return ans;
    }
};