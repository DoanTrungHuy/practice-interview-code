class Solution {
private:
    vector<int> flags, lows;
    int n;
    vector<vector<int>> adj, ans;
    int cnt;
        
public:
    void dfs(int u, int p) {
        flags[u] = lows[u] = ++cnt;
        
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            if (flags[v]) {
                lows[u] = min(lows[u], flags[v]);
            }
            else {
                dfs(v, u);
                lows[u] = min(lows[u], lows[v]);
                
                if (flags[u] < lows[v]) {
                    ans.push_back({u, v});
                }
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        this->n = n, this->cnt = 0;
        flags.resize(n), lows.resize(n);
        adj.resize(n);
        
        for (vector<int> connect : connections) {
            int u = connect[0];
            int v = connect[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0, -1);
        
        return ans;
    }
};