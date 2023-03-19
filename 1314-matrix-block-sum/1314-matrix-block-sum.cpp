class NumMatrix {
private:
    vector<vector<int>> matrix, dp;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        int n = matrix.size();
        int m = matrix[0].size();
        dp.resize(n + 1, vector<int>(m + 1));
        
        for (int i = 0; i < n; ++i) {
            int prefSum = 0;
            for (int j = 0; j < m; ++j) {
                prefSum += matrix[i][j];
                dp[i + 1][j + 1] += dp[i][j + 1] + prefSum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        return dp[row2][col2] - dp[row2][col1 - 1] - dp[row1 - 1][col2] + dp[row1 - 1][col1 - 1];
    }
};

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        NumMatrix nm(mat);
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int row1 = max(i - k, 0);
                int col1 = max(j - k, 0);
                int row2 = min(i + k, n - 1);
                int col2 = min(j + k, m - 1);
                ans[i][j] = nm.sumRegion(row1, col1, row2, col2);
            }
        }
        
        return ans;
    }
};