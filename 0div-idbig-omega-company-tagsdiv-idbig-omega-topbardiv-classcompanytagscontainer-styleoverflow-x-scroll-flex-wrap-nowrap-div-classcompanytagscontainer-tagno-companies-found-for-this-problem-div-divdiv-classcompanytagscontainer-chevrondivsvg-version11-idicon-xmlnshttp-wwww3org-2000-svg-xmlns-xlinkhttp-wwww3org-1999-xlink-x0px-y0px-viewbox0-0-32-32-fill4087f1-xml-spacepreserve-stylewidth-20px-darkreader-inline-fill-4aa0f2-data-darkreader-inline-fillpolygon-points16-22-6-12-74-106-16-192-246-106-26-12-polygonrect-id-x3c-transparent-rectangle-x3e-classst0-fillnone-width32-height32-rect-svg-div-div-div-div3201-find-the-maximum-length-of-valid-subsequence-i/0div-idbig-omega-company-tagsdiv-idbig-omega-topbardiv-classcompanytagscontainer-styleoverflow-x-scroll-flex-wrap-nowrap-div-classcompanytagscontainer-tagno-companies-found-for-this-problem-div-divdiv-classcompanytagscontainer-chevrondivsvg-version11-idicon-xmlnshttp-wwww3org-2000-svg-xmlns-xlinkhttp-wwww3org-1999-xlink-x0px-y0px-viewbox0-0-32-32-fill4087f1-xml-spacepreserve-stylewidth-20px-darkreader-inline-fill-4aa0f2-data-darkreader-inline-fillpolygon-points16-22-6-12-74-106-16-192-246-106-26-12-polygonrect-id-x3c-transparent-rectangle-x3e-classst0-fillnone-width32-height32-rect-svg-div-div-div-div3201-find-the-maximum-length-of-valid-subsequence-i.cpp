class Solution {
public:
    int dp[2][2];
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] & 1) {
                dp[1][0] = max(dp[1][0], dp[0][1] + 1);
                dp[1][1]++;
            }
            else {
                dp[0][1] = max(dp[0][1], dp[1][0] + 1);
                ++dp[0][0];
            }
        }
        return max({dp[0][0], dp[1][1], dp[0][1], dp[1][0]});
    }
};