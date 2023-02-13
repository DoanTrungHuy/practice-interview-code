class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri(numRows);
        
        for (int i = 1; i <= numRows; ++i) {
            vector<int> row(i, 1);
            for (int j = 1; j < i - 1; ++j) {
                row[j] = tri[i - 2][j - 1] + tri[i - 2][j];
            }
            tri[i - 1] = row;
        }
        
        return tri;
    }
};