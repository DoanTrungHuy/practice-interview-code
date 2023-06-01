const int MAXN = 1e5;
int memo[MAXN + 1];

class Solution {
public:
    bool dp(int n) {
        if (n == 0) {
            return false;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        for (int k = 1; k * k <= n; ++k) {
            if (!dp(n - k*k)) {
                return memo[n] = 1;
            }
        }
        return memo[n] = 0;
    }

    bool winnerSquareGame(int n) {
        memset(memo, -1, sizeof(memo));
        return dp(n) == 1;
    }
};