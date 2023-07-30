class Solution {
public:
    int helper(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int, int> um;
        int res = 0;
        
        for (int left = 0, right = 0; right < n; ++right) {
            um[nums[right]]++;
            while (um.size() > k) {
                if (--um[nums[left]] == 0) {
                    um.erase(nums[left]);
                }
                left++;
            }
            res += right - left + 1;
        }
        
        return res;
    }
    
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int k = us.size();
        
        return helper(nums, k) - helper(nums, k - 1);
    }
};