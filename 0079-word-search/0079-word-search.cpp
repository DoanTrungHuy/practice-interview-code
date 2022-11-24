class Solution {
private:
    int szWord;
    int r, c;
    vector<vector<char>> board;
    string word;
    int DIR[5] = {1, 0, -1, 0, 1};
    
public:
    bool isPath(int x, int y) {
        return 0 <= x and x < r and 0 <= y and y < c;
    }
    bool dfs(int x, int y, int k) {
        if (!isPath(x, y) or board[x][y] == '#' or board[x][y] != word[k]) {
            return false;
        }
        if (k == szWord - 1) {
            return true;
        }
        char chr = board[x][y];
        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            if (dfs(x + DIR[i], y + DIR[i + 1], k + 1)) {
                return true;
            }
        }
        board[x][y] = chr;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        szWord = word.size();
        r = board.size(), c = board[0].size();
        this->board = board;
        this->word = word;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};