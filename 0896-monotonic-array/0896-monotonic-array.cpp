class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool con1 = true, con2 = true;
        int n = nums.size();
        
        for (int i = 0; i < n - 1; ++i) {
            con1 &= (nums[i] <= nums[i + 1]);
            con2 &= (nums[i] >= nums[i + 1]);
        }
        
        return con1 or con2;
     }
};