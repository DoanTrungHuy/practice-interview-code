class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int u = 0, d = m - 1, l = 0, r = n - 1;
        
        vector<int> ans;
        
        while (u <= d and l <= r) {
            for (int col = l; col <= r; ++col) {
                ans.push_back(matrix[u][col]);
            }
            u++;
            if (u > d) {
                break;
            }
            for (int row = u; row <= d; ++row) {
                ans.push_back(matrix[row][r]);
            }
            r--;
            if (r < l) {
                break;
            }
            for (int col = r; col >= l; --col) {
                ans.push_back(matrix[d][col]);
            }
            d--;
            if (d < u) {
                break;
            }
            for (int row = d; row >= u; --row) {
                ans.push_back(matrix[row][l]);
            }
            l++;
            if (l > r) {
                break;
            }
        }
        
        return ans;
    }
};