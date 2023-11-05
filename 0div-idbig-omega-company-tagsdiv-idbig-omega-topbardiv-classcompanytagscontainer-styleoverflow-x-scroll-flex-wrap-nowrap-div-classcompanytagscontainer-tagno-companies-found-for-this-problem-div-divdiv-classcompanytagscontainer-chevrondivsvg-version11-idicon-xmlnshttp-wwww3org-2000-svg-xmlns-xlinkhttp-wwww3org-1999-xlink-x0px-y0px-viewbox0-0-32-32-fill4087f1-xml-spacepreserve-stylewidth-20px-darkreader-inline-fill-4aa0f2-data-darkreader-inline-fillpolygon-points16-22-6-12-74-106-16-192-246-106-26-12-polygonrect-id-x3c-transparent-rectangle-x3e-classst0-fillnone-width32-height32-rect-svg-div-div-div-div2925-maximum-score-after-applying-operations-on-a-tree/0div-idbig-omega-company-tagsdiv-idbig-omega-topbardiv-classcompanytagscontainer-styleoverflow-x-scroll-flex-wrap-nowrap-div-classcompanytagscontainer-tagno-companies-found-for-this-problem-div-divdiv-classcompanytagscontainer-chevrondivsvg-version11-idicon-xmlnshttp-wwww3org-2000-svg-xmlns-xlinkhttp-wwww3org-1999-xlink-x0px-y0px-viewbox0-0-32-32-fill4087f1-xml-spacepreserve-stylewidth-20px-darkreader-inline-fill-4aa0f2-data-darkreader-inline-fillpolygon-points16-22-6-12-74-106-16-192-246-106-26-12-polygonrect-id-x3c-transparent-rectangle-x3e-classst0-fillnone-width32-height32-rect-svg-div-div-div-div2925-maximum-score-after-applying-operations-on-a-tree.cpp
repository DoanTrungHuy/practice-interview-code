class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        function<long long(int, int)> dfs = [&](int u, int p) -> long long {
            if ((int)adj[u].size() == 1 and u) {
                return values[u];
            }
            long long sum = 0;
            for (int v : adj[u]) {
                if (v == p) {
                    continue;
                }
                sum += dfs(v, u);
            }
            return min(1LL*values[u], sum);
        };
        
        return accumulate(values.begin(), values.end(), 0LL) - dfs(0, -1);
    }
};
