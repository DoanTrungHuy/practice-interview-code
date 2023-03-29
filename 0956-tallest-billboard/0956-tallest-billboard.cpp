class Solution {
private:
    vector<int> rods;
    
public:
    const int limit = 10000;
    
    void dfs(int i, int n, int lSum, int rSum, unordered_map<int, int> &dp) {
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
        unordered_map<int, int> lSubset, rSubset;
        this->rods = rods;
        
        int n = rods.size();
        int mid = n >> 1;
        
        dfs(0, mid, 0, 0, lSubset);
        dfs(mid, n, 0, 0, rSubset);
        
        int ans = 0;
        
        for (auto [key, value] : lSubset) {
            if (rSubset.count(limit - key)) {
                ans = max(ans, lSubset[key] + rSubset[limit - key]);
            }
        }
        
        return ans;
    }
};