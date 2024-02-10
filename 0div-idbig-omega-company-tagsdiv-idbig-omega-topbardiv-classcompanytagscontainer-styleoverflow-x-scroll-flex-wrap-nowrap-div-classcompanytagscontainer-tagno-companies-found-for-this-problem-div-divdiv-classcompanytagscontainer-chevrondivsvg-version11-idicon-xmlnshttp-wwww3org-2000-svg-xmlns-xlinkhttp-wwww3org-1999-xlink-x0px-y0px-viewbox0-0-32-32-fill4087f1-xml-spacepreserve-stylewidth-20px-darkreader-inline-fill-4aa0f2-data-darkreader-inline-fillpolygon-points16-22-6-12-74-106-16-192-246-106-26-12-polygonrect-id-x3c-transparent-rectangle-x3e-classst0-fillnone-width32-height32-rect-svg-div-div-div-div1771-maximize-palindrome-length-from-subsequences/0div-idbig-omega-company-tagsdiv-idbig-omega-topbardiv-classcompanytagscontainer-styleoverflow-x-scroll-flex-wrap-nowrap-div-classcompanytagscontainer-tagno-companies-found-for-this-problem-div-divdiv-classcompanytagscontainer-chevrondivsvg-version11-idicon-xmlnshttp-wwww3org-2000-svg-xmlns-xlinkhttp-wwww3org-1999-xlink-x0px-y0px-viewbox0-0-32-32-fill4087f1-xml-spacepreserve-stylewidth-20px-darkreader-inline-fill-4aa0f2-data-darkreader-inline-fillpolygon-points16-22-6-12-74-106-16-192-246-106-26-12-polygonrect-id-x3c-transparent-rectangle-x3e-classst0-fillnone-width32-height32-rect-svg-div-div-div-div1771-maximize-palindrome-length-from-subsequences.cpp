const int MN = 2e3 + 10;

class Solution {
private:
    string s;
    
public:
    int memo[MN][MN];
    
    int dp(int i, int j) {
        if (j < i) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (s[i] == s[j]) {
            return memo[i][j] = 2 + dp(i + 1, j - 1);
        }
        return memo[i][j] = max(dp(i + 1, j), dp(i, j - 1));
    }
    
    int longestPalindrome(string word1, string word2) {
        s = word1 + word2;
        memset(memo, -1, sizeof(memo));
        const int n = s.size();
        
        int ans = 0;
        
        for (char c = 'a'; c <= 'z'; ++c) {
            int i = word1.find(c);
            int j = word2.rfind(c);
            if (i != string::npos and j != string::npos) {
                ans = max(ans, dp(i, word1.size() + j));
            }
        }
        
        return ans;
    }
};