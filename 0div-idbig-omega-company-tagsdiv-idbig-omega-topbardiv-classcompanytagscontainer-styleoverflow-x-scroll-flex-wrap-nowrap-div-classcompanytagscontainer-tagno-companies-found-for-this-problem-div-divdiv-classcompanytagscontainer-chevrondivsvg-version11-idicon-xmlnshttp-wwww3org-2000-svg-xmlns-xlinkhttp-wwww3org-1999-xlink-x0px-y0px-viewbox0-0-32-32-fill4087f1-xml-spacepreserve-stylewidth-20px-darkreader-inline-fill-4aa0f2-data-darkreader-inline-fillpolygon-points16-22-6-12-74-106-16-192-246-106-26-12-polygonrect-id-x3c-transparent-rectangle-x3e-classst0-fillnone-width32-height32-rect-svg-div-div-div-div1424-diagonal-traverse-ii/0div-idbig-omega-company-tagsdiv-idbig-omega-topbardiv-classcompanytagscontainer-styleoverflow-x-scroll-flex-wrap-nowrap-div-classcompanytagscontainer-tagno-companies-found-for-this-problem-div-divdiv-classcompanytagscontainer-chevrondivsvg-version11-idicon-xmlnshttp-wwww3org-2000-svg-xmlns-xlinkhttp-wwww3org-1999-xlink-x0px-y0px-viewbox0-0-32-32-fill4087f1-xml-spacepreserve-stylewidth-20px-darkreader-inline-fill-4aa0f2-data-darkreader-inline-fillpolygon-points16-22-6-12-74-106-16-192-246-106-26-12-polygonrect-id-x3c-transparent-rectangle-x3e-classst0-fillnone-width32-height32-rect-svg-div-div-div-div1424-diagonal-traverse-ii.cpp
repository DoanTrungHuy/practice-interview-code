class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> dia;
        const int n = nums.size();
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < (int)nums[i].size(); ++j) {
                dia[i - (n - j + 1)].push_back(nums[i][j]);
            }
        }
        
        vector<int> ans;
        
        for (const auto [v, lst] : dia) {
            for (int x : lst) {
                ans.push_back(x);
            }
        }
        
        return ans;
    }
};