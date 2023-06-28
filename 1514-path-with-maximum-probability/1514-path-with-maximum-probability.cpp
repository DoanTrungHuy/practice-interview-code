using pii = pair<double, int>;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pii>> adj(n);
        
        int m = edges.size();
        
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({succProb[i], v});
            adj[v].push_back({succProb[i], u});
        }
        
        priority_queue<pii> pq;
        vector<double> dist(n, 0);
        pq.push({dist[start] = 1.0, start});
        
        while (!pq.empty()) {
            auto [weight_u, u] = pq.top();
            pq.pop();
            
            for (auto [weight_v, v] : adj[u]) {
                if (weight_u*weight_v > dist[v]) {
                    dist[v] = weight_u*weight_v;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist[end];
    }
};