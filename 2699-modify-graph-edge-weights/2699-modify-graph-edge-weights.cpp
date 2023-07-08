using pii = pair<int, int>;

class Solution {
private:
    vector<vector<pii>> adj;
    int n;
    
public:
    const int oo = 2e9;

    vector<int> dijkstra(int sourse) {
        vector<int> dist(n, oo);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({dist[sourse] = 0, sourse});

        while (!pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();

            for (auto [dv, v] : adj[u]) {
                if (du + dv < dist[v]) {
                    dist[v] = du + dv;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
    
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        this->n = n;
        adj.resize(n);

        int m = edges.size();
        
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (w == -1) {
                continue;
            }

            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        vector<int> dist = dijkstra(source);
        
        if (dist[destination] < target) {
            return {};
        }

        if (dist[destination] == target) {
            for (int i = 0; i < m; ++i) {
                if (edges[i][2] == -1) {
                    edges[i][2] = oo;
                }
            }
            return edges;
        }

        for (int i = 0; i < m; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (w == -1) {
                edges[i][2] = 1;
                adj[u].push_back({1, v});
                adj[v].push_back({1, u});
                dist = dijkstra(source);

                if (dist[destination] <= target) {
                    edges[i][2] += target - dist[destination];
                    for (int j = i + 1; j < m; ++j) {
                        if (edges[j][2] == -1) {
                            edges[j][2] = oo;
                        }
                    }
                    return edges;
                }
            }
        }

        return {};
    }
};