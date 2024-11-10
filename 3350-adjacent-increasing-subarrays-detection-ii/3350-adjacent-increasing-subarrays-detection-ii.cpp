class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        const int n = nums.size();
        
        vector<int> dp(n);
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (i && nums[i] > nums[i - 1]) {
                ++cnt;
            } 
            else {
                cnt = 1;
            }
            dp[i] = cnt;
        }
        
        auto f = [&](int k) {
            for (int i = 0; i < n - 2*k + 1; ++i) {
                if (dp[i + k - 1] - dp[i] == dp[i + 2*k - 1] - dp[i + k] && dp[i + 2*k - 1] - dp[i + k] == k - 1) {
                    return true;
                }
            }
            
            return false;
        };
        
        int left = 1, right = n / 2;
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (f(mid)) {
                ans = mid;
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};
