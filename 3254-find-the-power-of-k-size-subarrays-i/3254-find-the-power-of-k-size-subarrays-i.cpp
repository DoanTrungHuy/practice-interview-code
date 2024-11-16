class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        
        vector<int> ans(n - k + 1, -1);
        multiset<int> ms;
        
        for (int i = 0; i < k - 1; ++i) {
            ms.insert(nums[i]);
        }
        
        for (int i = 0; i < n - k + 1; i++) {
            int l = i;
            int r = i + k - 1;
            
            ms.insert(nums[r]);
            
            if (dp[r] - dp[l] + 1 == k) {
                ans[i] = *ms.rbegin();
            }
            
            ms.erase(ms.lower_bound(nums[l]));
        }
        
        return ans;
    }
};