class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> p(n);
        p[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            p[i] = p[i - 1] + nums[i];
        }
        
        int ans = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            ans += (p[i] >= p[n - 1] - p[i]);
        }
        
        return ans;
    }
};