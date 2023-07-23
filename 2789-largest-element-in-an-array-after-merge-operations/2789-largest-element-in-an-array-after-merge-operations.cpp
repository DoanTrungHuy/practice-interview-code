class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        using ll = long long;
        vector<ll> ll_nums(nums.begin(), nums.end());
        const int n = nums.size();
        ll ans = nums[n - 1];
        
        for (int i = n - 2; i >= 0; --i) {
            if (ll_nums[i] <= ll_nums[i + 1]) {
                ll_nums[i] += ll_nums[i + 1];
            }
            ans = max(ans, ll_nums[i]);
        }
        
        return ans;
    }
};