class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int subOne = 0;
        int maxSub = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                subOne += 1;
            }
            else {
                subOne = 0;
            }
            maxSub = max(maxSub, subOne);
        }
        
        return maxSub;
    }
};