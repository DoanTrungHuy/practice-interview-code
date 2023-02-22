class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] <= nums[i - 1]) {
                if (cnt == 1) {
                    return false;
                }
                cnt += 1;
                if (i > 1 and nums[i - 2] >= nums[i]) {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return true;
    }
};