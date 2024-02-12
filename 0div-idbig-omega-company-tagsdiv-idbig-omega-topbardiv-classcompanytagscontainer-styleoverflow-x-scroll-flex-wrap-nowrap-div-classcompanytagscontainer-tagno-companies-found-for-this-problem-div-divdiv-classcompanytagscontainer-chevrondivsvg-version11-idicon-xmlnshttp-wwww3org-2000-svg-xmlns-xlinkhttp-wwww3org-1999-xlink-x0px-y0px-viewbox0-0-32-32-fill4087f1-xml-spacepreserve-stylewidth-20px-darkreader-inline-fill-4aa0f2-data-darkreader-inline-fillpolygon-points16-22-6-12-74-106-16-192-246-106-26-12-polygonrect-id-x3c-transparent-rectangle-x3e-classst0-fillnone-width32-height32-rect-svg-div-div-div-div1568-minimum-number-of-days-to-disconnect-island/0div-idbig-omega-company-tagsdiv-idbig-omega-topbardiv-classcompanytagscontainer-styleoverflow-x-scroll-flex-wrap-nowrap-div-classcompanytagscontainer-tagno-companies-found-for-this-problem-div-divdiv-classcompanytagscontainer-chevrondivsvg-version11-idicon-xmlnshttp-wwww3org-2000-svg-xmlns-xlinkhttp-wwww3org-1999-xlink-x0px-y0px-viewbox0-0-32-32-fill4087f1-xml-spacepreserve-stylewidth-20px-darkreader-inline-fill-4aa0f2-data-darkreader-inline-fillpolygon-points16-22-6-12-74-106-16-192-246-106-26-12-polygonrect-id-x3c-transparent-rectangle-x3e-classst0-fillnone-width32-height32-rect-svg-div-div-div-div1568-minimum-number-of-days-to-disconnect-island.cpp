class Solution {
private:
    vector<vector<int>> adj;
    vector<int> cur, low;
    int time = 0;
    vector<int> joint;
    
public:
    void dfs(int u, int p) {
        cur[u] = low[u] = ++time;
        
        int cnt_edge = 0;
        
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            if (cur[v]) {
                low[u] = min(low[u], cur[v]);
            }
            else {
                dfs(v, u);
                cnt_edge++;
                low[u] = min(low[u], low[v]);
                
                if (p == -1 and cnt_edge > 1) {
                    joint[u] = 1;
                }
                else if (p != -1 and low[v] >= cur[u]) {
                    joint[u] = 1 ;
                }
            }
        }
    }
    
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        adj.resize(n*m);
        vector<pair<int, int>> DIR = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        int cnt_one = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    cnt_one++;
                    for (auto [pi, pj] : DIR) {
                        int ni = i + pi;
                        int nj = j + pj;
                        if (0 <= ni and ni < n and 0 <= nj and nj < m) {
                            if (grid[ni][nj]) {
                                adj[i*m + j].push_back(ni*m + nj);
                            }
                        }
                    }
                }
            }
        }
        
        cur.resize(n*m);
        low.resize(n*m);
        joint.resize(n*m);
        
        int cnt_island = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] and cur[i*m + j] == 0) {
                    dfs(i*m + j, -1);
                    cnt_island++;
                }
            }
        }
        
        if (cnt_island > 1 or cnt_island == 0) {
            return 0;
        }
        
        int cnt_disconnect = 0;
        
        for (int i = 0; i < n*m; ++i) {
            cnt_disconnect += joint[i];
        }
        
        if (cnt_disconnect or cnt_one == 1) {
            return 1;
        }
        
        return 2;
    }
};