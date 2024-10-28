class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int sq = sqrt(nums[i]);

            if (sq*sq == nums[i] and dp.count(sq)) {
                dp[nums[i]] = dp[sq] + 1;
            }
            else if (dp.count(nums[i]) == 0) {
                dp[nums[i]] = 1;
            }
            
            ans = max(ans, dp[nums[i]]);
        }
        
        return (ans < 2) ? -1 : ans;
    }
};