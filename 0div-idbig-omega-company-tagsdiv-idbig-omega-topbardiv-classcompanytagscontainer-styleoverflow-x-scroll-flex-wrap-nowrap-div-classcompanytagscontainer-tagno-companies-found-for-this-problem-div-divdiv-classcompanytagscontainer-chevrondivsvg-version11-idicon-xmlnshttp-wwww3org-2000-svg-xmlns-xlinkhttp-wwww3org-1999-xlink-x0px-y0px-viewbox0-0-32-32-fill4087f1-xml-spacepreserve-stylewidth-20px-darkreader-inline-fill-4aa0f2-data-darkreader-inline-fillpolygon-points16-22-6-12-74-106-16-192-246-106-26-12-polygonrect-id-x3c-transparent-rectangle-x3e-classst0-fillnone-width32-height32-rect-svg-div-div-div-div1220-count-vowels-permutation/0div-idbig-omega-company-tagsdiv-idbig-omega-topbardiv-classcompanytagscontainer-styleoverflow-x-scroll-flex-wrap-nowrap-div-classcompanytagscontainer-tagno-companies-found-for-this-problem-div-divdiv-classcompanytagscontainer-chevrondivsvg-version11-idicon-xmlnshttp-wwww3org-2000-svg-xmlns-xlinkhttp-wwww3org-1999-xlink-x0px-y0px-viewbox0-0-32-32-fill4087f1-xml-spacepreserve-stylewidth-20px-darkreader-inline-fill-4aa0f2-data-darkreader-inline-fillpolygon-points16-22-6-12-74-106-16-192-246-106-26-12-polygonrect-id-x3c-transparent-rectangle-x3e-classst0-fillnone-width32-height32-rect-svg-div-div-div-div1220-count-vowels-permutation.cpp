using ll = long long;
const int MN = 2e4 + 1;
const int MOD = 1e9 + 7;
ll memo[MN][256];

class Solution {
public:
    ll dp(int i, char c) {
        if (i == 0) {
            return 1;
        }
        if (memo[i][c] != -1) {
            return memo[i][c];
        }
        if (c == '0') {
            return memo[i][c] = (dp(i - 1, 'u') + dp(i - 1, 'e') + dp(i - 1, 'o') + dp(i - 1, 'a') + dp(i - 1, 'i')) % MOD;
        }
        if (c == 'a') {
            return memo[i][c] = dp(i - 1, 'e') % MOD;
        }
        if (c == 'e') {
            return memo[i][c] = (dp(i - 1, 'a') + dp(i - 1, 'i')) % MOD;
        }
        if (c == 'i') {
            return memo[i][c] = (dp(i - 1, 'u') + dp(i - 1, 'e') + dp(i - 1, 'o') + dp(i - 1, 'a')) % MOD;
        }
        if (c == 'o') {
            return memo[i][c] = (dp(i - 1, 'i') + dp(i - 1, 'u')) % MOD;
        }
        return memo[i][c] = dp(i - 1, 'a') % MOD;
    }
    
    int countVowelPermutation(int n) {
        memset(memo, -1, sizeof(memo));
        return dp(n, '0');
    }
};