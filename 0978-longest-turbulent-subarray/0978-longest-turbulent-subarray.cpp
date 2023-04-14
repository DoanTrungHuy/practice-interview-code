class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        const int n = arr.size();
        int dp[n][2];
        memset(dp, 0, sizeof(dp));
        int maxLen = 0;
        
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] < arr[i]) {
                dp[i][1] = dp[i - 1][0] + 1;
                maxLen = max(maxLen, dp[i][1]);
            }
            else if (arr[i - 1] > arr[i]) {
                dp[i][0] = dp[i - 1][1] + 1;
                maxLen = max(maxLen, dp[i][0]);
            }
        }
        
        return maxLen + 1;
    }
};