class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0, s = 0;
        int j = 0, n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            while (j < n and s*(i - j + 1) >= k) {
                s -= nums[j];
                j++;
            }
            ans += i - j + 1;
        }
        
        return ans;
    }
};