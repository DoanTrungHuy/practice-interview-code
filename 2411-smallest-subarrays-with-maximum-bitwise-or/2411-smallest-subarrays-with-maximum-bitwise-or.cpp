class Solution {
public:
    vector<int> solve(vector<int> &nums, int n) {
        vector<int> ans;
        vector<int> bit(32, -1);
        
        for (int i = n - 1;i >= 0; --i) {
            for (int j = 0; j < 32; ++j) {
                if (nums[i] & (1 << j)) {
                    bit[j] = i;
                }
            }
            int last = i;
        
            for (int j = 0; j < 32; ++j) {
                last = max(last, bit[j]);
            }

            ans.push_back(last - i + 1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        return solve(nums, nums.size());
    }
};