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
            int max_dist = 0;
            int cnt_vertex = 0, cnt_edge = 0;
            
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) == 0) {
                    continue;
                }
                cnt_vertex++;
                for (int j = i + 1; j < n; ++j) {
                    if ((mask & (1 << j)) == 0) {
                        continue;
                    }
                    cnt_edge += dp[i][j] == 1;
                    max_dist = max(max_dist, dp[i][j]);
                }
            }
            
            if (max_dist != 0 and cnt_edge == cnt_vertex - 1) {
                ans[max_dist - 1]++;
            }
        }
        
        return ans;
    }
};