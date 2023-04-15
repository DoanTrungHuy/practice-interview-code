const int oo = INT_MAX;
using pi = pair<int, int>;

class Graph {
private:
    vector<pi> adj[105];
    int n;
    
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        } 
    }

    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
    }

    int shortestPath(int node1, int node2) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vector<int> d(n + 1, oo);
        d[node1] = 0;
        pq.push({0, node1});
        
        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();
            for(auto [v, w] : adj[node]){
                if(dist + w < d[v]){
                    d[v] = dist + w;
                    pq.push({d[v], v});
                }
            }
        }
        
        return d[node2] == oo ? -1 : d[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */