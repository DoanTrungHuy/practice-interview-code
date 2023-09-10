class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> dp(101);
        
        for (vector<int> n : nums) {
            for (int i = n[0]; i <= n[1]; ++i) {
                dp[i]++;
            }
        }
        
        int ans = 0;
        
        for (int i = 1; i <= 100; ++i) {
            ans += dp[i] != 0;
        }
        
        return ans;
    }
};