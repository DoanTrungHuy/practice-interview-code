class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        const int m = matrix[0].size();
        
        vector<int> heights(m);
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    heights[j] = 0;
                    continue;
                }
                heights[j] += matrix[i][j];
            }
            vector<int> tmp = heights;
            sort(tmp.begin(), tmp.end());
            int min_h = INT_MAX;
            for (int j = 0; j < m; ++j) {
                ans = max(ans, (m - j) * tmp[j]);
            }
        }
        
        return ans; 
    }
};