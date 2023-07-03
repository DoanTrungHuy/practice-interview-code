class Solution {
private:
    vector<vector<int>> grid;
    
public:
    int f(int target) {
        if (grid[0][0] > target) {
            return false;
        }
        
        queue<pair<int, int>> mq;
        mq.push({0, 0});
        
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        while (!mq.empty()) {
            auto [x, y] = mq.front();
            mq.pop();
            
            if (x == n - 1 and y == n - 1) {
                return true;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (0 <= nx and nx < n and 0 <= ny and ny < n) {
                    if (grid[nx][ny] <= target and !visited[nx][ny]) {
                        mq.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        this->grid = grid;
        int left = 0, right = 50*50;
        int ans = grid[0][0];
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (f(mid)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};