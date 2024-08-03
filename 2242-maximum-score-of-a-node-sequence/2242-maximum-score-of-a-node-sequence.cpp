class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        const int n = scores.size();
        using pii = pair<int, int>;
        
        vector<set<pii>> adj(n);
        
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].insert({scores[v], v});
            adj[v].insert({scores[u], u});
            
            if (adj[u].size() > 3) {
                adj[u].erase(adj[u].begin());
            }
            
            if (adj[v].size() > 3) {
                adj[v].erase(adj[v].begin());
            }
        }
        
        int ans = -1;
        
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            
            for (auto [ca, a] : adj[u]) {
                for (auto [cb, b] : adj[v]) {
                    if (a != b && a != v && b != u) {
                        ans = max(ans, scores[u] + scores[v] + ca + cb);
                    }
                }
            }
        }
        
        return ans;
    }
};
