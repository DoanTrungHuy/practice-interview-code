const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        
        using pii = pair<int, int>;
        
        queue<pii> mq;
        mq.push({0, 0});
        
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(m, INF));
        dist[0][0] = 0;
        
        while (mq.size()) {
            auto [x, y] = mq.front();
            mq.pop();
            
            if (n - 1 == x && m - 1 == y) {
                continue;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (0 <= nx && nx < n && 0 <= ny && ny < m && dist[x][y] + grid[nx][ny] < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + grid[nx][ny];
                    if (dist[nx][ny] > dist[n - 1][m - 1]) {
                        continue;
                    }
                    mq.push({nx, ny});
                }
            }
        }
        
        return dist[n - 1][m - 1];
    }
};