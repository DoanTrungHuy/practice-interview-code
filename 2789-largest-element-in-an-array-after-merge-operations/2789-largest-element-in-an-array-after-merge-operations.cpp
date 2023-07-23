class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        const int n = nums.size();
        long long ans = nums[n - 1];
        
        vector<long long> ll_nums(nums.begin(), nums.end());
        
        for (int i = n - 2; i >= 0; --i) {
            if (ll_nums[i] <= ll_nums[i + 1]) {
                ll_nums[i] += ll_nums[i + 1];
            }
            ans = max(ans, ll_nums[i]);
        }
        
        return ans;
    }
};