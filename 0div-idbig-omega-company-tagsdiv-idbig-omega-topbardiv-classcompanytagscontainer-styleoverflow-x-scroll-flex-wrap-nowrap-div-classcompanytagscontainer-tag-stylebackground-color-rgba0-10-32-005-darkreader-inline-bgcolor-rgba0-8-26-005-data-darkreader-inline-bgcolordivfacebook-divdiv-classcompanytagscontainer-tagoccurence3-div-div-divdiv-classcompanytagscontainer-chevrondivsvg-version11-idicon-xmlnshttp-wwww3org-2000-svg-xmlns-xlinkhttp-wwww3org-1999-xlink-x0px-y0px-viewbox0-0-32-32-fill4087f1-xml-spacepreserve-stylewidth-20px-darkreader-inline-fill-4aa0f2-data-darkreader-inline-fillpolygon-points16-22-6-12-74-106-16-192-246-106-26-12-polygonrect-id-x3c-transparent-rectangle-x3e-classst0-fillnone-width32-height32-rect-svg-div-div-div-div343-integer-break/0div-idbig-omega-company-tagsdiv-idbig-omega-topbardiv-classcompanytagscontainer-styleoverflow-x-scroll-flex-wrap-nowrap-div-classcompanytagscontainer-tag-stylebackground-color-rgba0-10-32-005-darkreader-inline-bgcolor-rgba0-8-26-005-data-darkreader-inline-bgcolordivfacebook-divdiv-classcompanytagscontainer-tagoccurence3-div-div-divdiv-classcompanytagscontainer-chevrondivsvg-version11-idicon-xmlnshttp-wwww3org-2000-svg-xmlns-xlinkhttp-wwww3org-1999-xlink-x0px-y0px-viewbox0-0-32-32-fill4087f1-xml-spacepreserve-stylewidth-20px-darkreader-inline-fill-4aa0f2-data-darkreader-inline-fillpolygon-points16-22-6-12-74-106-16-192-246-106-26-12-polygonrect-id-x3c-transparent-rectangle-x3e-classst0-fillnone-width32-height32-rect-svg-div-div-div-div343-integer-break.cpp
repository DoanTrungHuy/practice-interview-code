int memo[59][59][2];

class Solution {
private:
    int n;
    
public:
    int dp(int i, int s, bool c) {
        if (s == 0) {
            return c;
        }
        if (s < 0 or i > n) {
            return 0;
        }
        if (memo[i][s][c] != -1) {
            return memo[i][s][c];
        }
        int ans = 0;
        for (int j = i; j <= n; ++j) {
            ans = max(ans, j*dp(j, s - j, c and j != n));
        }
        return memo[i][s][c] = ans;
    }
    
    int integerBreak(int n) {
        this->n = n;
        memset(memo, -1, sizeof(memo));
        return dp(1, n, 1);
    }
};