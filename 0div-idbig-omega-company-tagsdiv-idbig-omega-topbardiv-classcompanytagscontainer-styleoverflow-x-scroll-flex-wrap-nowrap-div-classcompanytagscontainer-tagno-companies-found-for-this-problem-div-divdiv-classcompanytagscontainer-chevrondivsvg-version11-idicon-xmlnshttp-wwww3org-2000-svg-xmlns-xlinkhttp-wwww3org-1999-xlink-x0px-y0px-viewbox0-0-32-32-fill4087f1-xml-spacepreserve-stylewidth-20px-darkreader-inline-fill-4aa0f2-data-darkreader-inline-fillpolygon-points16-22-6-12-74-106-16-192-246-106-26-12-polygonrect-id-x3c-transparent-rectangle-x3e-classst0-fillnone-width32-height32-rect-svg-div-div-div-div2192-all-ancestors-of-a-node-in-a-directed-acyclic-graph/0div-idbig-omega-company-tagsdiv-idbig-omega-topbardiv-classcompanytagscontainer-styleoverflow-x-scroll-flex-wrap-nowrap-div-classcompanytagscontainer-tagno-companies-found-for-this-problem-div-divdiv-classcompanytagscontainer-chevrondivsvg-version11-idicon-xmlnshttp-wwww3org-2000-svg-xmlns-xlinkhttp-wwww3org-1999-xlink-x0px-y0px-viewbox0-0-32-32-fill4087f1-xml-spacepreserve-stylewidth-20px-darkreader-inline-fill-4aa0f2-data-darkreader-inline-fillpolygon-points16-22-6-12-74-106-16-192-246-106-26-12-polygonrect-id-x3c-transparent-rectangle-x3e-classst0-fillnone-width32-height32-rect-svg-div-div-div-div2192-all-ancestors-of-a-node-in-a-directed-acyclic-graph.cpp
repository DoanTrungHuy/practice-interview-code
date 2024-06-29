class Solution {
private:
    vector<vector<int>> adj;
    vector<int> tmp;
    vector<bool> visited;
    
public:
    void dfs(int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (visited[v]) {
                continue;
            }
            tmp.push_back(v);
            dfs(v);
        }    
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        
        for (vector<int> e : edges) {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }
        
        vector<vector<int>> ans(n);
        visited.resize(n, false);
        
        for (int i = 0; i < n; ++i) {
            dfs(i);
            ans[i] = tmp;   
            sort(ans[i].begin(), ans[i].end());
            for (int i = 0; i < n; ++i) {
                visited[i] = false;
            }
            tmp.clear();
        }
        
        return ans;
    }
};