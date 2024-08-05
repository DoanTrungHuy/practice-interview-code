int memo[1001][1001];

class Solution {
private:
    int n, m;
    vector<vector<int>> grid;
    
public:
    int dp(int i, int j) {
        if (i == n || j == m || j < 0) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (grid[i][j] == 1) {
            return memo[i][j] = 1 + min(
                {dp(i + 1, j - 1), dp(i + 1, j), dp(i + 1, j + 1)}
            );
        }
        return memo[i][j] = 0;
    }
    
    int countPyramids(vector<vector<int>>& grid) {
        memset(memo, -1, sizeof(memo));
        this->grid = grid;
        this->n = grid.size();
        this->m = grid[0].size();
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans += dp(i, j) - 1;
                }
            }
        }
        
        memset(memo, -1, sizeof(memo));
        
        reverse(grid.begin(), grid.end());
        this->grid = grid;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans += dp(i, j) - 1;
                }
            }
        }
        
        return ans;
    }
};