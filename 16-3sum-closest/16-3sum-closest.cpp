class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 3) {
            return nums[0] + nums[1] + nums[2];
        }
        sort(nums.begin(), nums.end());
        int dist = 1001;
        for (int i = 0; i < n; ++i) {
            int l = 0, r = n - 1;
            while (l < r) {
                if (l == i || r == i) {
                    l += 1;
                    r -= 1;
                    continue;
                }
                int numTarget = nums[i] + nums[l] + nums[r];
                if (numTarget == target) {
                    return target;
                }
                if (numTarget <= target) {
                    l += 1;
                } else {
                    r -= 1;
                }
                if (abs(target - numTarget) < abs(target - dist)) {
                    dist = numTarget;
                }
            }
        } 
        return dist;
    }
};