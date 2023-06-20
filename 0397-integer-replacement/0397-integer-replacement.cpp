class Solution {
public:
    int dp(int n) {
        if (n == INT_MAX) {
            return 32;
        }
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + dp(n / 2);
        }
        return 1 + min(dp(n - 1), dp(n + 1));
    }
    
    int integerReplacement(int n) {
        return dp(n);
    }
};