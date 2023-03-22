class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<string, int> um;
        
        for (int i = 0; i < n; ++i) {
            string s;
            for (int j = 0; j < m; ++j) {
                s += matrix[i][j] + '0';
            }
            um[s]++;
            for (int j = 0; j < m; ++j) {
                if (s[j] == '1') {
                    s[j] = '0';
                }
                else {
                    s[j] = '1';
                }
            }
            um[s]++;
        }
        
        int ans = 0;
        
        for (auto [_, cnt] : um) {
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};