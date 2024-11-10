class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        
        for (int i = 0; i < n - 2*k + 1; ++i) {
            bool flag = true;
            for (int j = i; j < i + k - 1; ++j) {
                if (nums[j] >= nums[j + 1]) {
                    flag = false;
                    break;
                }   
            }
            for (int j = i + k; j < i + 2*k - 1; ++j) {
                if (nums[j] >= nums[j + 1]) {
                    flag = false;
                    break;
                } 
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};