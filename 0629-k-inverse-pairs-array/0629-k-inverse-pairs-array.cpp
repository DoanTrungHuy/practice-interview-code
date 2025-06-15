class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[1001][1001];
    int prefix[1001][1001];

    int solve(int i, int inv, int n, int k) {
        if (i == n) {
            if (inv == k) {
                return 1;
            } else {
                return 0;
            }
        }
        if (dp[i][inv] != -1) {
            return dp[i][inv];
        }
        int maxJ = std::min(n - i - 1, k - inv);
        int left = inv - 1;
        int res = (prefix[i + 1][inv + maxJ] - (left >= 0 ? prefix[i + 1][left] : 0) + MOD) % MOD;
        dp[i][inv] = res;
        return res;
    }

    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        memset(prefix, 0, sizeof(prefix));
        for (int inv = 0; inv <= k; ++inv) {
            if (inv == k) {
                dp[n][inv] = 1;
            } else {
                dp[n][inv] = 0;
            }
        }
        prefix[n][0] = dp[n][0];
        for (int i = 1; i <= k; ++i) {
            prefix[n][i] = (prefix[n][i - 1] + dp[n][i]) % MOD;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int inv = 0; inv <= k; ++inv) {
                dp[i][inv] = solve(i, inv, n, k);
            }
            prefix[i][0] = dp[i][0];
            for (int j = 1; j <= k; ++j) {
                prefix[i][j] = (prefix[i][j - 1] + dp[i][j]) % MOD;
            }
        }
        return dp[0][0];
    }
};
