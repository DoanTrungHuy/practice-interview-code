const int maxn = 51;
int dp[maxn][maxn][maxn][maxn];

class Solution {
private:
    int n;
    vector<vector<int>> grid;
    
public:
    int dfs(int r1, int c1, int r2, int c2) {
        if (r1 == n or c1 == n or r2 == n or c2 == n) {
            return INT_MIN;
        }
        
        if (grid[r1][c1] == -1 or grid[r2][c2] == -1) {
            return INT_MIN;
        }
        
        if (dp[r1][c1][r2][c2] != -1) {
            return dp[r1][c1][r2][c2];
        }
        
        if (r1 == n - 1 and c1 == n - 1 and r2 == n - 1 and c2 == n - 1) {
            return grid[r1][c1];
        }
        
        int rr = dfs(r1, c1 + 1, r2, c2 + 1);
        int dd = dfs(r1 + 1, c1, r2 + 1, c2);
        int dr = dfs(r1 + 1, c1, r2, c2 + 1);
        int rd = dfs(r1, c1 + 1, r2 + 1, c2);
        
        int maxComb = max({rr, dd, dr, rd});
        
        if (r1 == r2 and c1 == c2) {
            maxComb += grid[r1][c1];
        }
        else {
            maxComb += grid[r1][c1] + grid[r2][c2];
        }
        
        return dp[r1][c1][r2][c2] = maxComb;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        this->n = grid.size();
        memset(dp, -1, sizeof(dp));
        this->grid = grid;
        return max(dfs(0, 0, 0, 0), 0);
    }
};