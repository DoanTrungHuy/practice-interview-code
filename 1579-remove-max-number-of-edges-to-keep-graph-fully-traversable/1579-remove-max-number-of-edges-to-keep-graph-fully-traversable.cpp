class DSU {
private:
    vector<int> parent;
    int group;
    
public:
    DSU() {
        
    }
    
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        this->group = n - 1;
    }
    
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    bool _union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        
        if (pu == pv) {
            return false;
        }
        
        parent[pu] = pv;
        group--;
        
        return true;
    }
    
    int get_group() {
        return group;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU Alice(n + 1), Bob(n + 1);
        int connect_edge = 0;
        int m = edges.size();
        
        for (int i = 0; i < m; ++i) {
            int t = edges[i][0];
            int u = edges[i][1], v = edges[i][2];
            
            if (t == 3) {
                connect_edge += (Alice._union(u, v) | Bob._union(u, v));
            }
        }
        
        for (int i = 0; i < m; ++i) {
            int t = edges[i][0];
            int u = edges[i][1], v = edges[i][2];
            
            if (t == 2) {
                connect_edge += Bob._union(u, v);
            }
            else if (t == 1) {
                connect_edge += Alice._union(u, v);
            }
        }
        
        if (Alice.get_group() == 1 and Bob.get_group() == 1) {
            return m - connect_edge;
        }
        
        return -1;
    }
};