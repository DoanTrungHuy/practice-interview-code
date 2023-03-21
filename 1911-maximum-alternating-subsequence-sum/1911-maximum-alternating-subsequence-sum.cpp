class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = nums[0];
        
        for (int i = 1; i < n; ++i) {
            ans += max(0, nums[i] - nums[i - 1]);
        }
        
        return ans;
    }
};