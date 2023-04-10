int dp[1001][101][2];

class Solution {
private:
    vector<int> prices;
    int n;
    
public:
    int dfs(int i, int k, int buy) {
        if (k == 0 or i == n) {
            return 0;
        }
        if (dp[i][k][buy] != -1) {
            return dp[i][k][buy];
        }
        if (buy == 1) {
            return dp[i][k][buy] = max(
                -prices[i] + dfs(i + 1, k, 0), 
                dfs(i + 1, k, 1)
            );
        }
        return dp[i][k][buy] = max(
            prices[i] + dfs(i + 1, k - 1, 1),
            dfs(i + 1, k, 0)
        );
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        this->prices = prices;
        this->n = prices.size();
        return dfs(0, k, 1);
    }
};