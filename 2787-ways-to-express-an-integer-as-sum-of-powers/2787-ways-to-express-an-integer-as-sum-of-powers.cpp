class Solution {
private:
    int x;
    
public:
    const int MOD = 1e9 + 7;
    
    int memo[301][301];
    
    int dp(int num, int n) {
        if (n == 0) {
            return 1;
        }
        
        if (n < 0) {
            return 0;
        }
        
        if (pow(num, x) > n) {
            return 0;
        }
        
        if (memo[num][n] != -1) {
            return memo[num][n];
        }
        
        int not_take = dp(num + 1, n);
        int take = dp(num + 1, n - pow(num, x));
        
        return memo[num][n] = (not_take + take) % MOD;
    }
    
    int numberOfWays(int n, int x) {
        memset(memo, -1, sizeof(memo));
        this->x = x;
        return dp(1, n);
    }
};