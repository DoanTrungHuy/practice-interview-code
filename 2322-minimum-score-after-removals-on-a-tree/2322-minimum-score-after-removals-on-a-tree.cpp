const int MN = 1000, LOG_MN = 10;

int rmq[MN][LOG_MN + 1];
int depth[MN], sum[MN];

class Solution {
private:
    vector<int> nums;
    vector<vector<int>> adj;
    int n;
    
public:
    void dfs(int u, int p) {
        sum[u] = nums[u];
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            rmq[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v, u);
            sum[u] ^= sum[v];
        }    
    }
    
    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        int diff = depth[u] - depth[v];
        for (int i = LOG_MN; i >= 0; --i) {
            if ((diff >> i) & 1) {
                u = rmq[u][i];
            }
        }
        if (u == v) {
            return u;
        }
        for (int i = LOG_MN; i >= 0; --i) {
            if (rmq[u][i] != rmq[v][i]) {
                u = rmq[u][i];
                v = rmq[v][i];
            }
        }
        return rmq[u][0];
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        this->n = nums.size();
        this->nums = nums;
        adj.resize(n);
        memset(rmq, -1, sizeof(rmq));
        
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0, -1);
        
        for (int lift = 1; lift <= LOG_MN; ++lift) {
            for (int node = 0; node < n; ++node) {
                if (rmq[node][lift - 1] != -1) {
                    rmq[node][lift] = rmq[rmq[node][lift - 1]][lift - 1];
                }
            }
        }
        
        
        int ans = INT_MAX;
        
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int node_lca = lca(i, j);
                
                int a, b, c;
                
                if (node_lca == i) {
                    a = sum[0] ^ sum[i];
                    b = sum[i] ^ sum[j];
                    c = sum[j];
                }
                else if (node_lca == j) {
                    a = sum[0] ^ sum[j];
                    b = sum[j] ^ sum[i];
                    c = sum[i];
                }
                else {
                    a = sum[0] ^ sum[i] ^ sum[j];
                    b = sum[i];
                    c = sum[j];
                }
                
                int ma = max({a, b, c});
                int mi = min({a, b, c});
                
                ans = min(ans, ma - mi);
            }
        }
        
        return ans;
    }
};