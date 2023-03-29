class Solution {
private:
    vector<int> rods;
    
public:
    const int limit = 10000;
    
    void dfs(int i, int n, int lSum, int rSum, int dp[]) {
        if (i == n) {
            int distance = lSum - rSum + (limit >> 1);
            dp[distance] = max(dp[distance], lSum);
            return;
        }
        dfs(i + 1, n, lSum + rods[i], rSum, dp);
        dfs(i + 1, n, lSum, rSum + rods[i], dp);
        dfs(i + 1, n, lSum, rSum, dp);
    }
    
    int tallestBillboard(vector<int>& rods) {
        int lSubset[limit + 1], rSubset[limit + 1];
        memset(lSubset, -1, sizeof(lSubset));
        memset(rSubset, -1, sizeof(rSubset));
        
        this->rods = rods;
        
        int n = rods.size();
        int mid = n >> 1;
        
        dfs(0, mid, 0, 0, lSubset);
        dfs(mid, n, 0, 0, rSubset);
        
        int ans = 0;
        
        for (int i = 0; i <= limit; ++i) {
            if (lSubset[i] != -1 and rSubset[limit - i] != -1) {
                ans = max(ans, lSubset[i] + rSubset[limit - i]);
            }
        }
        
        return ans;
    }
};