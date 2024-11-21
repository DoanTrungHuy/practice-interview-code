class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        const int GUARD = 1;
        const int WALL = 2;
        const int GUARDED = 3;

        for (vector<int> pos : guards) {
            grid[pos[0]][pos[1]] = GUARD;
        }
        
        for (vector<int> pos : walls) {
            grid[pos[0]][pos[1]] = WALL;
        }
        
        vector<int> DIR = {-1, 0, 1, 0, -1};

        auto mark_guarded = [&](int x, int y, int dx, int dy) {
            int nx = x + dx, ny = y + dy;
            while (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (grid[nx][ny] == WALL || grid[nx][ny] == GUARD) break;
                if (grid[nx][ny] == 0) grid[nx][ny] = GUARDED;
                nx += dx;
                ny += dy;
            }
        };

        for (vector<int> pos : guards) {
            for (int i = 0; i < 4; ++i) {
                mark_guarded(pos[0], pos[1], DIR[i], DIR[i + 1]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};
