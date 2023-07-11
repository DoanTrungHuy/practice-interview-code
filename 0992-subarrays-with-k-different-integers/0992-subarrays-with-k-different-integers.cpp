class Solution {
public:
    int sliding_window(vector<int>& nums, int k) {
        int j = 0, n = nums.size();
        int ans = 0;
        unordered_map<int, int> um;
        
        for (int i = 0; i < n; ++i) {
            um[nums[i]]++;
            while (j < n and um.size() > k) {
                um[nums[j]]--;
                if (um[nums[j]] == 0) {
                    um.erase(nums[j]);
                }
                j++;
            }
            ans += i - j + 1;
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sliding_window(nums, k) - sliding_window(nums, k - 1);
    }
};