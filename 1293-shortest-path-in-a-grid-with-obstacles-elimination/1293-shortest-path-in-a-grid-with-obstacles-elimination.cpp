class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        const int maxn = 41;
        bool visited[maxn][maxn][maxn * maxn];
        memset(visited, false, sizeof(visited));
        
        const int n = grid.size(), m = grid[0].size();
        const int dx[4] = {0, 0, -1, 1};
        const int dy[4] = {-1, 1, 0, 0};
        
        queue<tuple<int, int, int>> mq;
        mq.push({0, 0, k});
        visited[0][0][k] = true;
        int step = 0;
        
        while (!mq.empty()) {
            int size = mq.size();
            
            while (size--) {
                auto [x, y, unbuild] = mq.front();
                mq.pop();

                if (x == n - 1 and y == m - 1) {
                    return step;
                }

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (!(0 <= nx and nx < n and 0 <= ny and ny < m)) {
                        continue;
                    }

                    int newUnbuild = unbuild - grid[nx][ny];

                    if (newUnbuild >= 0 and !visited[nx][ny][newUnbuild]) {
                        mq.push({nx, ny, newUnbuild});
                        visited[nx][ny][newUnbuild] = true;
                    }
                }
            }
            
            step++;
        }
        
        return -1;
    }
};