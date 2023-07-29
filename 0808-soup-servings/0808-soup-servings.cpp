class Solution {
public:
    double memo[200][200];
    
    double dp(int a, int b) {
        if (a <= 0 and b <= 0) {
            return 0.5;
        }
        if (a <= 0) {
            return 1;
        }
        if (b <= 0) {
            return 0;
        }
        if (memo[a][b] > 0) {
            return memo[a][b];
        }
        return memo[a][b] = 0.25*(dp(a - 4, b) + dp(a - 3, b - 1) + dp(a - 2, b - 2) + dp(a - 1, b - 3));
    }
    
    double soupServings(int n) {
        if (n >= 4800) {
            return 1.0;
        }
        memset(memo, -1, sizeof(memo));
        return dp(ceill(n*1.0 / 25), ceil(n*1.0 / 25));
    }
};