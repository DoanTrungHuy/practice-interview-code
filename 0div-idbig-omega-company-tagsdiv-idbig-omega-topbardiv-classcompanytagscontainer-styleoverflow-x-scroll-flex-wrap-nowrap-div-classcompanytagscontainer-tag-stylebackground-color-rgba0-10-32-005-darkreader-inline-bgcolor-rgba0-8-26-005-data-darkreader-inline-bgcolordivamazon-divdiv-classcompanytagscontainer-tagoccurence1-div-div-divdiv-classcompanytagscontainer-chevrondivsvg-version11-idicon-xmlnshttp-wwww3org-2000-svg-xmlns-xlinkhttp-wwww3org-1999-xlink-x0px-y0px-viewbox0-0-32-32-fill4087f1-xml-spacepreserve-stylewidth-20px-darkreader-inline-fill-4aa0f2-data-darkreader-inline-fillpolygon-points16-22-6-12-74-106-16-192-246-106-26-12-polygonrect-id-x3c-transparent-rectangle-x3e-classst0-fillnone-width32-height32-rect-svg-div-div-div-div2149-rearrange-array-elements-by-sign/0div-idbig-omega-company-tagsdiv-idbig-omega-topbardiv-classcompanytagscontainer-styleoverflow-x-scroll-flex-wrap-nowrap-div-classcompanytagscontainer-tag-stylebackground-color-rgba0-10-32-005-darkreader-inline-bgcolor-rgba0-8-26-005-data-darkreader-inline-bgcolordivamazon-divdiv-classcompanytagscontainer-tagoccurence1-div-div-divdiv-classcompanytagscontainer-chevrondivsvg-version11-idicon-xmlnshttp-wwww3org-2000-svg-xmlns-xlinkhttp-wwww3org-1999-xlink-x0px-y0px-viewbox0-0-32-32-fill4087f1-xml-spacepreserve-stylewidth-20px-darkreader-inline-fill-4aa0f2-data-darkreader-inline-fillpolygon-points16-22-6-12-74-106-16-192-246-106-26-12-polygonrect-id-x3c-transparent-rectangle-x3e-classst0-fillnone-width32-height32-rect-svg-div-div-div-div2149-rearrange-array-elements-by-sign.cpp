class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n);
        int cnt_pos = 0;
        int j = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                ans[j] = nums[i];
                j += 2;
                cnt_pos++;
            }
            if (cnt_pos == n / 2) {
                break;
            }
        }
        
        int cnt_neg = 0;
        j = 1;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) {
                ans[j] = nums[i];
                j += 2;
                cnt_neg++;
            }
            if (cnt_neg == n / 2) {
                break;
            }
        }
        
        return ans;
    }
};