const int oo = 2e5;

class Solution {
private:
    vector<vector<int>> dp, cost;
    vector<int> minCost;
    int n, m;
    
public:
    int dfs(int i, int mask) {
        if (dp[i][mask] != -1) {
            return dp[i][mask];
        }
        if (i == n) {
            int remain = 0;
            for (int j = 0; j < m; ++j) {
                if (!(mask & (1 << j))) {
                    remain += minCost[j];
                }
            }
            return remain;
        }
        int ans = oo;
        for (int j = 0; j < m; ++j) {
            ans = min(ans, dfs(i + 1, mask | 1 << j) + cost[i][j]);
        }
        return dp[i][mask] = ans;
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        this->n = cost.size(), this->m = cost[0].size();
        this->cost = cost;
        minCost.resize(m, oo);
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                minCost[j] = min(minCost[j], cost[i][j]);
            }
        }
        dp.resize(n + 1, vector<int>(1 << m + 1, -1));
        return dfs(0, 0);
    }
};