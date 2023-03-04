class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<string>> dp(n + 1, vector<string>(m + 1));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
                }
                else {
                    if (dp[i][j - 1].size() > dp[i - 1][j].size()) {
                        dp[i][j] = dp[i][j - 1];
                    }
                    else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        
        string lcs = dp[n][m], res;
        int i = 0, j = 0;
        
        for (char c : lcs) {
            while (c != str1[i]) {
                res += str1[i];
                i++;
            }
            while (c != str2[j]) {
                res += str2[j];
                j++;
            }
            res += c;
            i++, j++;
        }
        
        return res + str1.substr(i) + str2.substr(j);
    }
};