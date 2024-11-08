class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int n = nums.size();
        
        int total_xor = 0;
        
        for (int i = 0; i < n; ++i) {
            total_xor ^= nums[i];
        }
        
        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i) {
            ans[i] = total_xor ^ ((1 << maximumBit) - 1);
            total_xor ^= nums[n - i - 1];
        }
        
        return ans;
    }
};