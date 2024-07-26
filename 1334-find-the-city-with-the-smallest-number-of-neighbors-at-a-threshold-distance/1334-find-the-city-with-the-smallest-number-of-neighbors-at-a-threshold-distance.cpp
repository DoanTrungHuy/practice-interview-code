class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        for (vector<int> &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        for (int k = 0; k < n; ++k) {
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    if (u != v && dist[u][k] != INF && dist[k][v] != INF) {
                        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                    }
                }
            }
        }
        
        int node_valid = -1;
        int mn = INF;
        
        for (int u = 0; u < n; ++u) {
            int cnt = 0;
            for (int v = 0; v < n; ++v) {
                if (u == v) {
                    continue;
                }
                cnt += dist[u][v] <= distanceThreshold;
            }
            if (mn >= cnt) {
                mn = cnt;
                node_valid = u;
            }
        }
        
        return node_valid;
    }
};