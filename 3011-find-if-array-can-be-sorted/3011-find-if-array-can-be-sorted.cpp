class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        const int n = nums.size();
        
        vector<vector<int>> grp;
        int prev_bit = __builtin_popcount(nums[0]);
        vector<int> tmp = {nums[0]};
        
        for (int i = 1; i < n; ++i) {
            int curr_bit = __builtin_popcount(nums[i]);
            if (curr_bit == prev_bit) {
                tmp.push_back(nums[i]);
            }
            else {
                grp.push_back(tmp);
                prev_bit = curr_bit;
                tmp = {nums[i]};
            }
        }
        
        grp.push_back(tmp);
        tmp.clear();
        int prev_val = 0;
        
        for (int i = 0; i < grp.size(); ++i) {
            sort(grp[i].begin(), grp[i].end());
            for (int j = 0; j < grp[i].size(); ++j) {
                if (prev_val > grp[i][j]) {
                    return false;
                }
                prev_val = grp[i][j];
            }
        }
    
        return true;
    }
};