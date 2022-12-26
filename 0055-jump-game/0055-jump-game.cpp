class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxDist = 0;
        for (int i = 0; i < n; ++i) {
            if (i > maxDist) {
                return false;
            }
            maxDist = max(maxDist, i + nums[i]);
        }
        return true;
    }
};