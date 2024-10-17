using pii = pair<int, int>;
const int MN = 101;
const int INF = 1e9;
int dist[MN];

class Graph {
private:
    vector<pii> adj[105];
    int n;
    
    // adj[fromi] = {{toi, weighti}, {}}
    
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        
        for (vector<int> e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }
    }
    
    void addEdge(vector<int> e) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
        adj[u].push_back({v, w});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        for (int i = 0; i < MN; ++i) {
            dist[i] = INF;
        }
        
        pq.push({dist[node1] = 0, node1});
        
        while (pq.size()) {
            auto [du, u] = pq.top();
            pq.pop();
            
            if (du != dist[u]) {
                continue;
            }
            
            if (u == node2) {
                return du;
            }
            
            for (auto [v, w] : adj[u]) {
                if (du + w < dist[v]) {
                    pq.push({dist[v] = du + w, v});
                }
            }
        }
        
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */