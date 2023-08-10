class TreeAncestor {
private:
    vector<vector<int>> par;
    int m;
    
public:
    TreeAncestor(int n, vector<int>& parent) {
        this->m = log2(n) + 1;
        par.resize(n, vector<int>(m, -1));
        
        for (int u = 0; u < n; ++u) {
            par[u][0] = parent[u];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int u = 0; u < n; ++u) {
                if (par[u][i - 1] != -1) {
                    par[u][i] = par[par[u][i - 1]][i - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = m; i >= 0; --i) {
            if ((k >> i) & 1) {
                node = par[node][i];
                if (node == -1) {
                    return node;
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