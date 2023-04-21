const int MAXN = 102, MOD = 1e9 + 7, MAXPROFIT = 101;
int memo[MAXN][MAXN][MAXN];

class Solution {
private:
    vector<int> group, profit;
    int minProfit;
    
public:
    int dp(int i, int p, int n) {
        if (i == group.size()) {
            return p >= minProfit;
        }
        
        if (memo[i][p][n] != -1) {
            return memo[i][p][n];
        }
        
        memo[i][p][n] = dp(i + 1, p, n) % MOD;
        
        if (n - group[i] >= 0) {
            memo[i][p][n] = (memo[i][p][n] + dp(i + 1, min(p + profit[i], MAXPROFIT), n - group[i])) % MOD;
        }
        
        return memo[i][p][n];
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(memo, -1, sizeof(memo));
        this->group = group;
        this->profit = profit;
        this->minProfit = minProfit;
        return dp(0, 0, n);
    }
};