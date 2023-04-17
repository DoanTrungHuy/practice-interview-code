class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int m = words[0].size(), n = target.size();
        const int MOD = 1e9 + 7;
        
        int freq[m][26];
        memset(freq, 0, sizeof(freq));
        
        for (string word : words) {
            for (int j = 0; j < m; ++j) {
                freq[j][word[j] - 'a']++;
            }
        }
        
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i <= m; ++i) {
            dp[i][n] = 1;
        }
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
                dp[i][j] = (dp[i][j] + (long)dp[i + 1][j + 1] * freq[i][target[j] - 'a']) % MOD;
            }
        }
        
        return dp[0][0];
    }
};