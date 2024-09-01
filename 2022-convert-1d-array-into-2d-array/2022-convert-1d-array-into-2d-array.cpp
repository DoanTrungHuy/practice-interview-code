class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m*n != original.size()) {
            return {};
        }
        
        vector<vector<int>> ans;
        vector<int> tmp;
        int cnt_c = 0;
        
        for (int i = 0; i < original.size(); ++i) {
            cnt_c++;
            tmp.push_back(original[i]);
            if (cnt_c == n) {
                ans.push_back(tmp);
                tmp = {};
                cnt_c = 0;
            }
        }
        
        return ans;
    }
};