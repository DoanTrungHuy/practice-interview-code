class Solution {
private:
    int m, n;
    int ans = 0;
    int sum = 0;
    vector<pair<int, int>> DIR = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
public:
    void dfs(vector<vector<int>> &grid, int i, int j) {
        int tmp = grid[i][j];
        sum += grid[i][j];
        grid[i][j] = 0;
        ans = max(ans, sum);
        for (auto [dx, dy] : DIR) {
            if (0 <= i + dx and i + dx < m and 0 <= j + dy and j + dy < n and grid[i + dx][j + dy]) {
                dfs(grid, i + dx, j + dy);
            }
        }
        sum -= tmp;
        grid[i][j] = tmp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};