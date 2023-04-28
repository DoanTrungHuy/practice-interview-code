class Solution {
public:
    int numberOfArrays(string s, int k) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;
        
        for (int i = n - 1; i >= 0; --i) {
            long long num = 0;
            if (s[i] == '0') {
                continue;
            }
            for (int j = i; j < n; ++j) {
                num = num*10 + (s[j] - '0');
                if (num > k) {
                    break;
                }
                dp[i] = (dp[i] + dp[j + 1]) % MOD;
            }
        }
        
        return dp[0];
    }
};