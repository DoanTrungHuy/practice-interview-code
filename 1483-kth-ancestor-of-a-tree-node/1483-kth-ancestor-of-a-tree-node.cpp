class TreeAncestor {
private:
    vector<vector<int>> up;
    int m;
    
public:
    TreeAncestor(int n, vector<int>& parent) {
        this->m = log2(n) + 1;
        up.resize(n, vector<int>(m, -1));
        
        for (int u = 0; u < n; ++u) {
            up[u][0] = parent[u];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int u = 0; u < n; ++u) {
                if (up[u][i - 1] == -1) {
                    continue;
                }
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < m; ++i) {
            if ((k >> i) & 1) {
                node = up[node][i];
                if (node == -1) {
                    return -1;
                }
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */