class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // nums[i] == nums[j] and abs(i - j) <= k.
        const int n = nums.size();
        map<int, int> mm;
        
        for (int i = 0; i < n; ++i) {
            if (mm.count(nums[i]) and i - mm[nums[i]] <= k) {
                return true;
            }
            mm[nums[i]] = i;
        }
        
        return false;
    }
};