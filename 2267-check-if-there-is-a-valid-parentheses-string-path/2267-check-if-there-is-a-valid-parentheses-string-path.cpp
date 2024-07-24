int memo[101][101][201];

class Solution {
private:
    vector<vector<char>> grid;
    int n, m;
    
public:
    int dp(int i, int j, int opened) {
        if (i == n || j == m) {
            return 0;
        }
        if (grid[i][j] == '(') {
            opened++;
        }
        else {
            opened--;
        }
        if (opened < 0) {
            return 0;
        }
        if (i == n - 1 and j == m - 1) {
            return opened == 0;
        }
        if (memo[i][j][opened] != -1) {
            return memo[i][j][opened];
        }
        return memo[i][j][opened] = dp(i + 1, j, opened) | dp(i, j + 1, opened);
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        this->grid = grid;
        memset(memo, -1, sizeof(memo));
        this->n = grid.size();
        this->m = grid[0].size();
        return dp(0, 0, 0);
    }
};