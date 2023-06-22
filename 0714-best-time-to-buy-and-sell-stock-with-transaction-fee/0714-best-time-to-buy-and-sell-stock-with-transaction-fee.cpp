const int MAXN = 1e5;
int memo[MAXN + 5][2];

class Solution {
private:
    vector<int> prices;
    int fee;
    int n;
    
public:
    int dp(int i, bool state) {
        if (i == n) {
            return 0;
        }
        if (memo[i][state] != -1) {
            return memo[i][state];
        }
        if (state == 0) {
            return memo[i][state] = max(
                -prices[i] + dp(i + 1, !state), 
                dp(i + 1, state)
            );
        }
        else {
            return memo[i][state] = max(
                prices[i] - fee + dp(i + 1, !state), 
                dp(i + 1, state)
            );
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        this->prices = prices;
        this->fee = fee;
        this->n = prices.size();
        memset(memo, -1, sizeof(memo));
        return dp(0, 0);
    }
};