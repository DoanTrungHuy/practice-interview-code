class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        using ll = long long;
        ll ans = 0;
        const int n = nums.size();
        int prev = nums[n - 1];
        
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > prev) {
                int t = ceil(nums[i]*1.0/prev);
                ans += (t - 1);
                prev = nums[i] / t;
            }
            else {
                prev = nums[i];
            }
        }
        
        return ans;
    }
};