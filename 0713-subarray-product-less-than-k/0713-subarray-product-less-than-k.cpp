class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) {
            return 0;
        }
        
        int n = nums.size();
        int ans = 0;
        int pro = 1;
        
        for (int i = 0, j = 0; i < n; ++i) {
            pro *= nums[i];
            while (j <= i and pro >= k) {
                pro /= nums[j++];
            }
            ans += i - j + 1;
        }
        
        return ans;
    }
};