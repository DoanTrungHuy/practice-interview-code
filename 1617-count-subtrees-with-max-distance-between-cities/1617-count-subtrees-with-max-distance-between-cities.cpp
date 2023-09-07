class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        const int oo = n;
        vector<vector<int>> dp(n, vector<int>(n, oo));
        
        for (vector<int> edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            dp[u][v] = dp[v][u] = 1;
        }
        
        for (int k = 0; k < n; ++k) {
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
                }
            }
        }
        
        vector<int> ans(n - 1);
        
        for (int mask = 1; mask < (1 << n); ++mask) {
            vector<int> v;
            
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    v.push_back(i);
                }
            }
            
            int max_dist = 0;
            int m = v.size();
            int cnt_edge = 0;
            
            for (int i = 0; i < m; ++i) {
                for (int j = i + 1; j < m; ++j) {
                    cnt_edge += dp[v[i]][v[j]] == 1;
                    max_dist = max(max_dist, dp[v[i]][v[j]]);
                }
            }
            
            if (max_dist != 0 and cnt_edge == m - 1) {
                ans[max_dist - 1]++;
            }
        }
        
        return ans;
    }
};