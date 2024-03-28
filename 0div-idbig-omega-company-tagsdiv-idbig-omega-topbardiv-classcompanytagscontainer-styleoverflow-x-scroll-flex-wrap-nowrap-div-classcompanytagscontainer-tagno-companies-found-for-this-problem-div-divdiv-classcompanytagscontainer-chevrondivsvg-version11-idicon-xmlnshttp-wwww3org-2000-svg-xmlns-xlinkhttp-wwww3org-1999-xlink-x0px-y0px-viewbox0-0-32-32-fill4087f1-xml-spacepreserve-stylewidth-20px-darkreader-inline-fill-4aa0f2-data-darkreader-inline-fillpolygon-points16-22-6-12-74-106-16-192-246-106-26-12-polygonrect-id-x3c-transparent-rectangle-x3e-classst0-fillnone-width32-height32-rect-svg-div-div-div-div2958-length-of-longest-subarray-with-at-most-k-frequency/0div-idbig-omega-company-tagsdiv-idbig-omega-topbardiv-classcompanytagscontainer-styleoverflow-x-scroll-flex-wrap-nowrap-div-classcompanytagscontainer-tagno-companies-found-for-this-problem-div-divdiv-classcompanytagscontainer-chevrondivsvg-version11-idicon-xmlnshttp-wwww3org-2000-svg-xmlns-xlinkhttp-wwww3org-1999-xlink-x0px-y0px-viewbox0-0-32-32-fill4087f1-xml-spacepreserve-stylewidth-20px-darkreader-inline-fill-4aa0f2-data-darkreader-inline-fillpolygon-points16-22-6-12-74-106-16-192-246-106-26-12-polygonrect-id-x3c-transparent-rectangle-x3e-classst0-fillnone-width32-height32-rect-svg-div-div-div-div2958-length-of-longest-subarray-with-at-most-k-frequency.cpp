class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const int n = nums.size();
        map<int, int> mm;
        int ans = 0, j = 0;
        
        for (int i = 0; i < n; ++i) {
            mm[nums[i]]++;
            while (mm[nums[i]] > k) {
                mm[nums[j]]--;
                if (mm[nums[j]] == 0) {
                    mm.erase(nums[j]);
                }
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};