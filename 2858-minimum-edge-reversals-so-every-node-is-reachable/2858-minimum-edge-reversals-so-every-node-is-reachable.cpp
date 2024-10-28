class Solution {
private:
    vector<vector<int>> adj, r_adj;
    
public:
    const int MN = 1e5 + 10;
    map<pair<int, int>, int> memo;
    
    int dp(int u, int p) {
        if (memo.count({u, p})) {
            return memo[{u, p}];
        }
        int ans = 0;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            ans += dp(v, u);
        }
        for (int v : r_adj[u]) {
            if (v == p) {
                continue;
            }
            ans += dp(v, u) + 1;
        }
        return memo[{u, p}] = ans;
    }
    
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        // dp(u) -> for v in adj[u]: min(dp[v])
        // dp(u) -> for v in r_adj[u]: min(dp[v] + 1)
        
        adj.resize(n);
        r_adj.resize(n);
        
        for (vector<int> e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            r_adj[v].push_back(u);
        }
        
        vector<int> ans;
        
        for (int i = 0; i < n; ++i) {
            ans.push_back(dp(i, -1));
        }
        
        return ans;
    }
};