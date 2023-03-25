class Solution {
private:
    vector<vector<int>> adj;
    vector<bool> visited;
    
public:
    long long dfs(int u) {
        visited[u] = true;
        int len = 1;
        for (int v : adj[u]) {
            if (!visited[v]) {
                len += dfs(v);
            }
        }
        return len;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        adj.resize(n), visited.resize(n, false);
        
        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        long long ans = 0, totalNode = 0;
        
        for (int u = 0; u < n; ++u) {
            if (!visited[u]) {
                int cnt = dfs(u);
                ans += cnt * totalNode;
                totalNode += cnt;
            }
        }
        
        return ans;
    }
};