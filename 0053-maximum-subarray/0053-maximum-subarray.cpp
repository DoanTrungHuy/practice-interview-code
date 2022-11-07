class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int ans = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            maxSub = max(nums[i], maxSub + nums[i]);
            ans = max(ans, maxSub);
        }
        return ans;
    }
};