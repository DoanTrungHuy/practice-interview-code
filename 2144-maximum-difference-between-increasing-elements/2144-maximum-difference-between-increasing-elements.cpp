class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        const int n = nums.size();
        int ans = -1;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j]) {
                    continue;
                }

                ans = max(ans, nums[j] - nums[i]);
            }
        }

        return ans;
    }
};