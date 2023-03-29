class Solution {
private:
    vector<int> rods;
    
public:
    void dfs(int i, int n, int lSum, int rSum, vector<int> &dp) {
        if (i == n) {
            int distance = lSum - rSum + 5000;
            dp[distance] = max(dp[distance], lSum);
            return;
        }
        dfs(i + 1, n, lSum + rods[i], rSum, dp);
        dfs(i + 1, n, lSum, rSum + rods[i], dp);
        dfs(i + 1, n, lSum, rSum, dp);
    }
    int tallestBillboard(vector<int>& rods) {
        vector<int> lSubset(10001, -1);
        vector<int> rSubset(10001, -1);
        
        this->rods = rods;
        
        int n = rods.size();
        int mid = n >> 1;
        
        dfs(0, mid, 0, 0, lSubset);
        dfs(mid, n, 0, 0, rSubset);
        
        int ans = 0;
        
        for (int i = 0; i <= 10000; ++i) {
            if (lSubset[i] != -1 and rSubset[10000 - i] != -1) {
                ans = max(ans, lSubset[i] + rSubset[10000 - i]);
            }
        }
        
        return ans;
    }
};