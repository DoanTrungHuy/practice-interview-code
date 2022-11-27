class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        using ll = long long;
        vector<unordered_map<ll, int>> dp(n);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                ll diff = (ll)nums[i] - nums[j];
                int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += cnt + 1;
                ans += cnt;
            }
        }
        return ans;
    }
};