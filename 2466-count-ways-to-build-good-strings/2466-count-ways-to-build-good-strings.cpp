class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[100005];
    int helper(int target, int one, int zero) {
        if (target < 0) {
            return 0;
        }
        if (target == 0) {
            return 1;
        }
        if (dp[target] != -1) {
            return dp[target];
        }
        int cnt = (helper(target - zero, one, zero) % MOD + helper(target - one, one, zero) % MOD) % MOD;
        return dp[target] = cnt;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        for (int i = 0; i <= high; ++i) {
            dp[i] = -1;
        }
        int cnt = 0;
        for (int i = low; i <= high; ++i) {
            cnt = ((cnt % MOD) + helper(i, one, zero) % MOD) % MOD;
        }
        return cnt;
    }
};