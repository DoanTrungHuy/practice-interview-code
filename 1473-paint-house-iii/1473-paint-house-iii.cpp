int memo[101][101][21];

class Solution {
private:
    vector<int> houses;
    vector<vector<int>> cost;
    int n;
    int m;
    
public:
    int dp(int i, int target, int prev) {
        if (target < 0) {
            return 1e9;
        }
        if (i == m) {
            if (target == 0) {
                return 0;
            }
            return 1e9;
        }
        if (memo[i][target][prev] != -1) {
            return memo[i][target][prev];
        }
        int ans = 1e9;
        for (int c = 1; c <= n; ++c) {
            if (houses[i] == 0) {
                ans = min(ans, cost[i][c - 1] + dp(i + 1, target - (prev != c), c));
            }
            else {
                ans = min(ans, dp(i + 1, target - (prev != houses[i]), houses[i]));
            }
        }
        return memo[i][target][prev] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // n = 20
        // m = 100
        // dp(im, target, prev)
        
        memset(memo, -1, sizeof(memo));
        this->houses = houses;
        this->cost = cost;
        this->n = n;
        this->m = m;
        
        return (dp(0, target, 0) == 1e9) ? -1 : dp(0, target, 0);
    }
};