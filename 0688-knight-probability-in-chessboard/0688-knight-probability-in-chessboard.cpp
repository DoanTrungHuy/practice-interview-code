class Solution {
private:
    vector<vector<vector<double>>> memo;
    int n;
    
public:
    vector<pair<int, int>> dir = {
        {-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}
    };
    
    double dp(int row, int column, int k) {
        if (!(0 <= row and row < n and 0 <= column and column < n)) {
            return 0;
        }
        
        if (k == 0) {
            return 1;
        }
        
        if (memo[row][column][k] != -1) {
            return memo[row][column][k];
        }
        
        double sum = 0;
        
        for (auto [x, y] : dir) {
            sum += dp(row + x, column + y, k - 1);
        }
        
        return memo[row][column][k] = sum / 8;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        this->n = n;
        memo.resize(n + 1, vector<vector<double>>(n + 1, vector<double>(k + 1, -1)));
        return dp(row, column, k);
    }
};