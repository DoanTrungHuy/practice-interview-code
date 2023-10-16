const int MOD = 1e9 + 7;
int memo[501][501];

class Solution {
public:
    int dp(int i, int j, int steps, int n) {
        if (i == steps) {
            return j == 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int ans = dp(i + 1, j, steps, n) % MOD;
        if (j - 1 >= 0) {
            ans = (ans + dp(i + 1, j - 1, steps, n)) % MOD;
        }
        if (j + 1 < n) {
            ans = (ans + dp(i + 1, j + 1, steps, n)) % MOD;
        }
        return memo[i][j] = ans;
    }
    
    int numWays(int steps, int arrLen) {
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, steps, arrLen);
    }
};