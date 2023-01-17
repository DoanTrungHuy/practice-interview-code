class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int n, m;
    
    bool isValid(int x, int y) {
        return 0 <= x and x < n and 0 <= y and y < m;
    }
    
    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny) and grid[nx][ny] == '1') {
                dfs(grid, nx, ny);   
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};