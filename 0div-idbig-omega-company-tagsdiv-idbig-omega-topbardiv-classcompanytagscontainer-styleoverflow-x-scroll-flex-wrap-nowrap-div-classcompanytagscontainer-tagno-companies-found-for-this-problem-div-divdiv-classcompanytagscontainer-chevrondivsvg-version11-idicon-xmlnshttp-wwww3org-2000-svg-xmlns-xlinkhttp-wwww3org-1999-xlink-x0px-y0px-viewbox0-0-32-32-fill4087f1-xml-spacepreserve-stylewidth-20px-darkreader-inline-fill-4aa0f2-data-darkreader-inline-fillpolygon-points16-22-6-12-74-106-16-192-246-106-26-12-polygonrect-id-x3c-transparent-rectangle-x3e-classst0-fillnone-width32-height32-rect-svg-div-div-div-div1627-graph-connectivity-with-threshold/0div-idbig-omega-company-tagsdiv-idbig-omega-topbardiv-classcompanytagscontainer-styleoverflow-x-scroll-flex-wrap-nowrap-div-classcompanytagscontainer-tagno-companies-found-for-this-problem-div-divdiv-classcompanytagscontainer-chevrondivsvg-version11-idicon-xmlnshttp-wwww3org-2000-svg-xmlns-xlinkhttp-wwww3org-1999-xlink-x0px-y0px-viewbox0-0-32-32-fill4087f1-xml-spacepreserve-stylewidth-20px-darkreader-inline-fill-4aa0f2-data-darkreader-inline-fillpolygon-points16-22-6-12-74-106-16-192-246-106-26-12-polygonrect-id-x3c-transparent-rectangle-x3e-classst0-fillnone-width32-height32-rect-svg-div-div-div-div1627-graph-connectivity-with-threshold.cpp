struct DSU {
    vector<int> parent;
    
    DSU() {
        
    }
    
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    
    bool _union(int u, int v) {
        u = find(u);
        v = find(v);
        
        if (u == v) {
            return false;
        }
        
        parent[u] = v;
        
        return true;
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU dsu(n);
        
        for (int t = threshold + 1; t <= n; ++t) {
            for (int j = t*2; j <= n; j += t) {
                dsu._union(t, j);
            }
        }
        
        vector<bool> ans;
        
        for (vector<int> q : queries) {
            int u = q[0];
            int v = q[1];
            
            ans.push_back(dsu.find(u) == dsu.find(v));
        }
        
        return ans;
    }
};