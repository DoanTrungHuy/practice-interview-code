class Solution {
private:
    int n;
    vector<vector<int>> dp;
    
public:
    int rec(int amount, vector<int>& coins, int j) {
        if (amount < 0) {
            return 0;
        }
        if (amount == 0) {
            return 1;
        }
        if (dp[amount][j] != -1) {
            return dp[amount][j];
        }
        int res = 0;
        for (int i = j; i < n; ++i) {
            res += rec(amount - coins[i], coins, i);
        }
        dp[amount][j] = res; 
        return res;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.resize(amount + 1, vector<int>(n, -1));
        return rec(amount, coins, 0);
    }
};