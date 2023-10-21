class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        using tp = tuple<int, int, int>;
        priority_queue<tp, vector<tp>, greater<tp>> pq;
        const int n = grid.size();
        const int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
                    pq.push({grid[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        int total = 0;
        
        while (!pq.empty()) {
            auto [curr_height, x, y] = pq.top();
            pq.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (!(0 <= nx and nx < n and 0 <= ny and ny < m)) {
                    continue;
                }
                if (visited[nx][ny]) {
                    continue;
                }
                if (grid[nx][ny] < curr_height) {
                    total += curr_height - grid[nx][ny];
                    pq.push({curr_height, nx, ny});
                }
                else {
                    pq.push({grid[nx][ny], nx, ny});
                }
                visited[nx][ny] = true;
            }
        }
        
        return total;
    }
};