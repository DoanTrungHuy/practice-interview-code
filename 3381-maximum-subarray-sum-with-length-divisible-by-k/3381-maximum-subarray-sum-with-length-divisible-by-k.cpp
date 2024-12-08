class Solution {
public:
    using ll = long long;
    
    long long maxSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        
        vector<ll> pref(n + 1, 0), dp(k, LLONG_MAX);
        
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        
        ll ans = LLONG_MIN;
        
        // pref[i] - min(pref[j]) (has j module k)
        
        for (int i = 0; i <= n; i++) {
            if (i >= k) {
                ans = max(ans, pref[i] - dp[i % k]);
            }
            dp[i % k] = min(dp[i % k], pref[i]);
        }
        
        if (ans == LLONG_MIN) {
            return 0;
        }
        
        return ans; 
    }
};