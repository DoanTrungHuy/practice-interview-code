class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, int> lastIndex, maxDiff;
        
        
        for (int i = 0; i < n; ++i) {
            maxDiff[nums[i]] = max(maxDiff[nums[i]], i - lastIndex[nums[i]] - 1);
            lastIndex[nums[i]] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            maxDiff[nums[i]] = max(maxDiff[nums[i]], (i - lastIndex[nums[i]] - 1 + n) % n);
            lastIndex[nums[i]] = i;
        }
        
        int diff = 2*n;
        
        for (auto [_, v] : maxDiff) {
            diff = min(diff, v);
        }
        
        return ceil(1.0*diff/2);
    }
};