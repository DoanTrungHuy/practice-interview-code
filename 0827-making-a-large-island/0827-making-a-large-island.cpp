class Solution {
private:
    vector<vector<int>> components, grid;
    unordered_map<int, int> sizes;
    int n;
    
public:
    const int di[4] = {-1, 1, 0, 0};
    const int dj[4] = {0, 0, -1, 1};
    
    bool isValid(int i, int j) {
        return 0 <= i and i < n and 0 <= j and j < n;
    }
    
    int dfs(int i, int j, int color) {
        if (!isValid(i, j)) {
            return 0;
        }
        if (!(grid[i][j] == 1 and components[i][j] == -1)) {
            return 0;
        }
        components[i][j] = color;
        int cnt = 1;
        for (int p = 0; p < 4; ++p) {
            cnt += dfs(i + di[p], j + dj[p], color);
        }
        return cnt;
    }
        
    int largestIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        components.resize(n, vector<int>(n, -1));
        int color = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] and components[i][j] == -1) {
                    sizes[color] = dfs(i, j, color);
                    color++;
                }
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    unordered_set<int> setColor;
                    for (int p = 0; p < 4; ++p) {
                        int ni = i + di[p];
                        int nj = j + dj[p];
                        if (!isValid(ni, nj)) {
                            continue;
                        }
                        if (grid[ni][nj]) {
                            setColor.insert(components[ni][nj]);
                        }
                    }
                    
                    int totalSize = 0;
                    
                    for (int color : setColor) {
                        totalSize += sizes[color];
                    }
                    
                    ans = max(ans, totalSize + 1);
                }
            }
        }
        
        return ans == 0 ? n*n : ans;
    }
};