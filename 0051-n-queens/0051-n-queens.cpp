class Solution {
private:
    vector<string> nQueens;
    vector<vector<string>> ans;
    int row, col;
    
public:
    bool canGo(int i, int j) {
        for (int x = 0; x < i; ++x) {
            if (nQueens[x][j] == 'Q') {
                return false;
            }
        }
        for (int x = i, y = j; x >= 0 and y >= 0; --x, --y) {
            if (nQueens[x][y] == 'Q') {
                return false;
            }
        }
        for (int x = i, y = j; x >= 0 and y >= 0; --x, ++y) {
            if (nQueens[x][y] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void backTracking(int i) {
        if (i == row) {
            ans.push_back(nQueens);
        }
        for (int j = 0; j < col; ++j) {
            if (canGo(i, j)) {
                nQueens[i][j] = 'Q';
                backTracking(i + 1);
                nQueens[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        nQueens.resize(n, string(n, '.'));
        row = col = n;
        backTracking(0);
        return ans;
    }
};