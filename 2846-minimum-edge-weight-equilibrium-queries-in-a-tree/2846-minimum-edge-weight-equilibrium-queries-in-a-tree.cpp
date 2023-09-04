using pii = pair<int, int>;
const int MW = 26;

class Solution {
private:
    vector<vector<pii>> adj;
    vector<vector<int>> par, clr;
    vector<int> depth;
    int n, m;
    
public:
    void dfs(int u, int p, int c) {
        par[u][0] = p;
        depth[u] = c;
        for (const auto &[v, w] : adj[u]) {
            if (v == p) {
                continue;
            }
            for (int i = 0; i < MW; ++i) {
                clr[v][i] = clr[u][i] + (i == w);
            }
            dfs(v, u, c + 1);
        }
    }
    
    int get_node_lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        
        int diff = depth[u] - depth[v];
        
        for (int i = m; i >= 0; --i) {
            if ((diff >> i) & 1) {
                u = par[u][i];
            }
        }
        
        if (u == v) {
            return u;
        }
        
        for (int i = m; i >= 0; --i) {
            if (par[u][i] != par[v][i]) {
                u = par[u][i];
                v = par[v][i];
            }
        }
        
        return par[u][0];
    }
    
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        this->n = n;
        adj.resize(n);
        
        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            w--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        depth.resize(n);
        m = ceil(log2(n));
        par.resize(n, vector<int>(m + 1, -1));
        clr.resize(n, vector<int>(MW));
        dfs(0, -1, 1);
        
        for (int j = 1; j <= m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (par[i][j - 1] != -1) {
                    par[i][j] = par[par[i][j - 1]][j - 1];
                }
            }
        }
        
        int sz_q = (int)queries.size();
        
        vector<int> ans(sz_q, n);
        
        for (int j = 0; j < sz_q; ++j) {
            int u = queries[j][0];
            int v = queries[j][1];
            int node_lca = get_node_lca(u, v);
            int len = depth[u] + depth[v] - 2 * depth[node_lca];
            for (int i = 0; i < MW; ++i) {
                int try_num = (clr[u][i] + clr[v][i] - 2 * clr[node_lca][i]);
                ans[j] = min(ans[j], len - try_num);
            }
        }
        
        return ans;
    }
};