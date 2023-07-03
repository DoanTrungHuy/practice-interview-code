class Solution {
private:
    vector<vector<int>> heights;
    
public:
    bool f(int threshould) {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        queue<pair<int, int>> mq;
        mq.push({0, 0});
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;
        
        while (!mq.empty()) {
            auto [x, y] = mq.front();
            mq.pop();
            
            if (x == n - 1 and y == m - 1) {
                return true;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                    if (!visited[nx][ny] and abs(heights[x][y] - heights[nx][ny]) <= threshould) {
                        mq.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        this->heights = heights;
        
        int left = 0, right = 1e6;
        int ans = 0;
        
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