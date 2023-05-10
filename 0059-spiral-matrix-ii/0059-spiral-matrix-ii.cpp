class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int u = 0, d = n - 1, l = 0, r = n - 1;
        int val = 0;
        vector<vector<int>> ans(n, vector<int>(n));
        
        while (u <= d and l <= r) {
            for (int col = l; col <= r; ++col) {
                ans[l][col] = (++val);
            }
            u++;
            if (u > d) {
                break;
            }
            for (int row = u; row <= d; ++row) {
                ans[row][r] = (++val);
            }
            r--;
            if (r < l) {
                break;
            }
            for (int col = r; col >= l; --col) {
                ans[d][col] = (++val);
            }
            d--;
            if (d < u) {
                break;
            }
            for (int row = d; row >= u; --row) {
                ans[row][l] = (++val);
            }
            l++;
            if (l > r) {
                break;
            }
        }
        
        return ans;  
    }
};