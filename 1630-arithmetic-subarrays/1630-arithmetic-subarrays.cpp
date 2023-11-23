class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        const int n = nums.size();
        const int m = r.size();
        vector<bool> ans(m, false);
        
        for (int i = 0; i < m; ++i) {
            vector<int> tmp;
            for (int j = l[i]; j <= r[i]; ++j) {
                tmp.push_back(nums[j]);
            }
            sort(tmp.begin(), tmp.end());
            int diff = tmp[0] - tmp[1];
            bool flag = true;
            for (int j = 0; j < (int)tmp.size() - 1; ++j) {
                if (tmp[j] - tmp[j + 1] != diff) {
                    flag = false;
                    break;
                }
            }
            ans[i] = (flag);
        }
        
        return ans;
    }
};