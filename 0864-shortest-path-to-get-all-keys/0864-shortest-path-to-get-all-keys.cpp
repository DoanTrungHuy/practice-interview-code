class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int containsKey = 0;
        int n = grid.size(), m = grid[0].size();
        
        queue<tuple<int, int, int>> mq;
        const int numKey = 6;
        bool visited[n][m][1 << numKey];
        memset(visited, false, sizeof(visited));
        
        int keys = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '@') {
                    mq.push({i, j, 0});
                    visited[i][j][0] = true;
                }
                
                if ('a' <= grid[i][j] and grid[i][j] <= 'f') {
                    keys++;
                }
            }
        }
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        int step = 0;
        
        while (!mq.empty()) {
            int size = mq.size();
            while (size--) {
                auto [x, y, mask] = mq.front();
                mq.pop();
                
                if (mask == (1 << keys) - 1) {
                    return step;
                }

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (0 <= nx and nx < n and 0 <= ny and ny < m and grid[nx][ny] != '#') {
                        if ('A' <= grid[nx][ny] and grid[nx][ny] <= 'F') {
                            if (!(mask & (1 << (grid[nx][ny] - 'A')))) {
                                continue;
                            }
                        }
                        
                        int newMask = mask;
                        
                        if ('a' <= grid[nx][ny] and grid[nx][ny] <= 'f') {
                            newMask |= (1 << (grid[nx][ny] - 'a'));
                        }
                        
                        if (!visited[nx][ny][newMask]) {
                            mq.push({nx, ny, newMask});
                            visited[nx][ny][newMask] = true;
                        }
                    }
                }
            }
            step += 1;
        }
        
        return -1;
    }
};