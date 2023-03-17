class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minNum = nums[0];
        int maxDiff = -1;
        
        for (int i = 1; i < (int)nums.size(); ++i) {
            maxDiff = max(maxDiff, nums[i] - minNum);
            minNum = min(minNum, nums[i]);
        }
        
        return maxDiff == 0 ? -1 : maxDiff;
    }
};