class Solution {
private:
    vector<vector<int>> adj;
    int n;
    vector<int> res;
    
public:
    int dfs(int u, vector<int> &quiet) {
        if (res[u] >= 0) {
            return res[u];
        }
        res[u] = u;
        for (int v : adj[u]) {
            if (quiet[res[u]] > quiet[dfs(v, quiet)]) {
                res[u] = res[v];
            }
        }
        return res[u];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        this->n = quiet.size();
        adj.resize(n);
        
        for (auto r : richer) {
            int u = r[0], v = r[1];
            adj[v].push_back(u);
        }
        
        res.resize(n, -1);

        for (int i = 0; i < n; ++i) {
            res[i] = dfs(i, quiet);
        }
        
        return res;
    }
};