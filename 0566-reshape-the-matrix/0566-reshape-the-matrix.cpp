class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        
        if (!(r*c == n*m)) {
            return mat;
        }
        
        vector<int> arr;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                arr.push_back(mat[i][j]);
            }
        }
        
        int sz = arr.size();
        int j = 0;
        
        vector<vector<int>> ans(r);
        
        for (int i = 0; i < r; ++i) {
            int cnt = 0;
            while (cnt < c) {
                ans[i].push_back(arr[j++]);
                cnt++;
            }
        }
        
        return ans;
    }
};