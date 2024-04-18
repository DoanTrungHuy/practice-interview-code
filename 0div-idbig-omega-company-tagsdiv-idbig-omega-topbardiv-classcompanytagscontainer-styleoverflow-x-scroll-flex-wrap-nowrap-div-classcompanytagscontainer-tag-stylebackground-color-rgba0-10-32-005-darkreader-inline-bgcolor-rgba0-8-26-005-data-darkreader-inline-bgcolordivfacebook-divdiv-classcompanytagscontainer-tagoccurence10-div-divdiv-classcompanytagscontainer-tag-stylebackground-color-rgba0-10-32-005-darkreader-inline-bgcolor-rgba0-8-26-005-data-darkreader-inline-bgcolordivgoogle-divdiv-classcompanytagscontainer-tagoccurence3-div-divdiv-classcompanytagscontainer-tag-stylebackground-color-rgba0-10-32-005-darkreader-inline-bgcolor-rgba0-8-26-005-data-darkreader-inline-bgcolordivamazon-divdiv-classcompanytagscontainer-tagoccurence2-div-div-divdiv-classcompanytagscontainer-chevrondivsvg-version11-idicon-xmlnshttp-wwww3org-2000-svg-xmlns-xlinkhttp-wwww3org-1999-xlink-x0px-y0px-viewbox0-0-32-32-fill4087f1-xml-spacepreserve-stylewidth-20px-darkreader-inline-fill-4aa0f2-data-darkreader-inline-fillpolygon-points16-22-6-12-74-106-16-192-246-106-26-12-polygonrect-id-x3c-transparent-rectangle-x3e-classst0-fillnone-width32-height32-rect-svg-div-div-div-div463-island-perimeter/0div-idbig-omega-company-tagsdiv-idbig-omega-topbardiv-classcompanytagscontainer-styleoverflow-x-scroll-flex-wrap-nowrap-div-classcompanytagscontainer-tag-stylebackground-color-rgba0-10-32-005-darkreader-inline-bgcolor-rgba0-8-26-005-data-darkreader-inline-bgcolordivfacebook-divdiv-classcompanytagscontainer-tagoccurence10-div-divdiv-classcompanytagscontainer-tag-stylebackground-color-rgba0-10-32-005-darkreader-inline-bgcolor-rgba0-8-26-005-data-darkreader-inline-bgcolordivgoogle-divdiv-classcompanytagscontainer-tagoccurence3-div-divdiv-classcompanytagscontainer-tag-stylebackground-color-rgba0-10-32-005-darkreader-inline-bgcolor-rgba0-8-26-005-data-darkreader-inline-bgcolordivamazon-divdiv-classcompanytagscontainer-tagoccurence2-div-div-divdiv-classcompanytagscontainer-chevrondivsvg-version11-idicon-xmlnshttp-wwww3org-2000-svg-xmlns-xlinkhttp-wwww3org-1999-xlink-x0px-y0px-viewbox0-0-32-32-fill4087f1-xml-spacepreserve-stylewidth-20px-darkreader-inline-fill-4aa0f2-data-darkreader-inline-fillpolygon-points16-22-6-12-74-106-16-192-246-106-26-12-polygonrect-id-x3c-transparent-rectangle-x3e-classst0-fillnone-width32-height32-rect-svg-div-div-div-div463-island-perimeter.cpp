class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int di[4] = {-1, 1, 0, 0};
        int dj[4] = {0, 0, -1, 1};
        
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; ++d) {
                        int ni = i + di[d];
                        int nj = j + dj[d];
                        
                        if (!(0 <= ni and ni < n and 0 <= nj and nj < m) or !grid[ni][nj]) {
                            cnt++;
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
};