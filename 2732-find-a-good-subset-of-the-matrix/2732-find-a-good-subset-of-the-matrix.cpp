class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, int> hash;
        
        for (int i = 0; i < m; ++i) {
            int mask = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    mask |= (1 << j);
                }
            }
            
            if (mask == 0) {
                return {i};
            }
            
            for (int j = 1; j < (1 << 5); ++j) {
                if ((mask & j) == 0 and hash.count(j)) {
                    return {hash[j], i};
                }
            }
            
            hash[mask] = i;
        }
        
        return {};
    }
};