class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = (int)graph.size();
        vector<vector<bool>> dp(n, vector<bool>(1 << n, false));
        
        queue<tuple<int, int, int>> mq;
        
        for (int i = 0; i < n; ++i) {
            dp[i][1 << i] = true;
            mq.push({i, 1 << i, 0});
        }
        
        int res = (1 << n) - 1;
        
        while (!mq.empty()) {
            auto [u, mask, step] = mq.front();
            mq.pop();
            if (mask == res) {
                return step;
            }
            for (int v : graph[u]) {
                int maskV = mask | (1 << v);
                if (!dp[v][maskV]) {
                    mq.push({v, maskV, step + 1});
                    dp[v][maskV] = true;
                }
            }
        }
        
        return -1;
    }
};