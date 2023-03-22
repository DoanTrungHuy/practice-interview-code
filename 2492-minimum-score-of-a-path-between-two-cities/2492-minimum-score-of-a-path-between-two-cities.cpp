using pi = pair<int, int>;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pi>> adj(n + 1);
        
        for (vector<int> road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];
            
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        queue<pi> mq;
        
        mq.push({0, 1});
        
        while (!mq.empty()) {
            auto [du, u] = mq.front();
            mq.pop();
            
            for (auto [dv, v] : adj[u]) {
                if (dv < dist[v] or dist[u] < dist[v]) {
                    dist[v] = min(dv, dist[u]);
                    mq.push({dist[v], v});
                }
            }
        }
        
        return dist[n];
    }
};