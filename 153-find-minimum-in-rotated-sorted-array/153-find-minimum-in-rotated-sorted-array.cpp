class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int i = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (m > 0 and m + 1 < n and nums[m - 1] > nums[m] and nums[m + 1] > nums[m]) {
                return nums[m];
            }
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                i = m;
                r = m - 1;
            }
        }
        return nums[i];
    }
};