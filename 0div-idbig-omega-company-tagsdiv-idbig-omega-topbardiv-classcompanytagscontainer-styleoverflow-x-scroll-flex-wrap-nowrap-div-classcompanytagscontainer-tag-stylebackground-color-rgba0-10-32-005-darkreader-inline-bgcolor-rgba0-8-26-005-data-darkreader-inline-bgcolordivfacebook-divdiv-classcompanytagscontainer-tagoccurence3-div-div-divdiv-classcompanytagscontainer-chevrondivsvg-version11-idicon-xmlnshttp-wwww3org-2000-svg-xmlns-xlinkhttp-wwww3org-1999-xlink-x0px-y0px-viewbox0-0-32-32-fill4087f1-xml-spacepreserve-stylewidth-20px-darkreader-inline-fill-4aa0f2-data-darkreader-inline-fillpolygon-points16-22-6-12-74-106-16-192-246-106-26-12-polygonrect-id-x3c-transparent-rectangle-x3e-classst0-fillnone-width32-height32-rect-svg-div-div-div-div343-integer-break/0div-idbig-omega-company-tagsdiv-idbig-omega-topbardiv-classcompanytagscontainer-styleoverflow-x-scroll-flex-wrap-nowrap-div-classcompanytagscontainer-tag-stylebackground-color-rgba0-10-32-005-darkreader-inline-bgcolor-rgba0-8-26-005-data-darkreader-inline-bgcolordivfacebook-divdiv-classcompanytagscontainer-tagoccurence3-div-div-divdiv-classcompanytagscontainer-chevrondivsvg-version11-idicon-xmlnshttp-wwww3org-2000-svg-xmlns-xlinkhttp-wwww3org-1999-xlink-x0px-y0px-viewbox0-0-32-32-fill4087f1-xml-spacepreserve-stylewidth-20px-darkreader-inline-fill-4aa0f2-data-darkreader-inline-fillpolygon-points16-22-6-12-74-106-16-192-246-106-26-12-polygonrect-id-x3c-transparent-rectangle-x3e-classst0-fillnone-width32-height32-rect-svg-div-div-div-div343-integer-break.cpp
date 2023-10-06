int memo[59][59];

class Solution {
private:
    int n;
    
public:
    int dp(int i, int s) {
        if (s == 0) {
            return 1;
        }
        if (s < 0 or i > n) {
            return 0;
        }
        if (memo[i][s] != -1) {
            return memo[i][s];
        }
        int ans = 0;
        for (int j = i; j < n; ++j) {
            ans = max(ans, j*dp(j, s - j));
        }
        return memo[i][s] = ans;
    }
    
    int integerBreak(int n) {
        this->n = n;
        memset(memo, -1, sizeof(memo));
        return dp(1, n);
    }
};