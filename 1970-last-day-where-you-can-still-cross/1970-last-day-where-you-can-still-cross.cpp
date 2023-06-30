class Solution {
private:
    vector<vector<int>> cells;
    int row, col;
    
public:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
    
    bool f(int day) {
        vector<vector<int>> grid(row, vector<int>(col));
        
        for (int i = 0; i < day; ++i) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 1;
        }
        
        queue<pair<int, int>> mq;
        
        for (int j = 0; j < col; ++j) {
            if (grid[0][j] == 0) {
                mq.push({0, j});
                grid[0][j] = 1;
            }
        }
        
        while (!mq.empty()) {
            auto [x, y] = mq.front();
            mq.pop();
            
            if (x == row - 1) {
                return true;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx and nx < row and 0 <= ny and ny < col and grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    mq.push({nx, ny});
                }
            }
        }
        
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        this->cells = cells;
        this->row = row, this->col = col;
        
        int left = 0, right = cells.size() - 1;
        int ans = 0;
        
        while (left <= right) {
            int mid = (right + left) / 2;
            
            if (f(mid)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};