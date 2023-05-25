class Solution {
private:
    vector<vector<int>> g;
    int n;
    
public:
    int dfs(int i, int j) {
        if (!(0 <= i and i < 3*n and 0 <= j and j < 3*n)) {
            return 0;
        }
        if (g[i][j]) {
            return 0;
        }
        g[i][j] = 1;
        return 1 + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i - 1, j) + dfs(i, j + 1);
    }
    
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        g.resize(3*n, vector<int>(3*n, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    g[3*i][3*j + 2] = g[3*i + 1][3*j + 1] = g[3*i + 2][3*j] = 1;
                }
                else if (grid[i][j] == '\\') {
                    g[3*i][3*j] = g[3*i + 1][3*j + 1] = g[3*i + 2][3*j + 2] = 1;
                }
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < 3*n; ++i) {
            for (int j = 0; j < 3*n; ++j) {
                if (g[i][j]) {
                    continue;
                }
                ans += dfs(i, j) > 0;
            }
        }
        
        return ans;
    }
};