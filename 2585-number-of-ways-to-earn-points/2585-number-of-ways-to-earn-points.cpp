class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        const int mod = 1e9 + 7;
        int n = types.size();
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = target; j >= 1; --j) {
                for (int k = 1; k <= types[i][0] and j - k*types[i][1] >= 0; ++k) {
                    dp[j] += dp[j - k*types[i][1]];
                    dp[j] %= mod;
                }
            }
        }
        return dp[target];
    }
};