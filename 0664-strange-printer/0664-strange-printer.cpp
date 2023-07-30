class Solution {
private:
    string s;
    
public:
    int memo[101][101];
    
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
        int ans = 1 + dp(i + 1, j);
        for (int k = i + 1; k <= j; ++k) {
            if (s[i] == s[k]) {
                ans = min(ans, dp(i + 1, k - 1) + dp(k, j));
            }
        }
        return memo[i][j] = ans;
    }
    
    int strangePrinter(string s) {
        this->s = s;
        memset(memo, -1, sizeof(memo));
        int n = s.size();
        return dp(0, n - 1);
    }
};