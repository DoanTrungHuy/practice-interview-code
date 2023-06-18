const int MOD = 1e9 + 7;
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
int memo[1001][1001];

class Solution {
private:
    vector<vector<int>> grid;
    int n, m;
    
public:
    int dp(int i, int j) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int ans = 0;
        for (int k = 0; k < 4; ++k) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (0 <= ni and ni < n and 0 <= nj and nj < m and grid[i][j] < grid[ni][nj]) {
                ans = (ans + dp(ni, nj)) % MOD;
            }
        }
        return memo[i][j] = (ans + 1) % MOD;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m = grid[0].size();
        this->grid = grid;
        memset(memo, -1, sizeof(memo));
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = (ans + dp(i, j)) % MOD;
            }
        }
        
        return ans;
    }
};