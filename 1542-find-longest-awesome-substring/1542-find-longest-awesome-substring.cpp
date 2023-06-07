class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> dp;
        dp[0] = -1;
        int n = s.size(), mask = 0, ans = 0;
        
        for (int i = 0; i < n; ++i) {
            mask ^= 1 << (s[i] - '0');
            
            for (int j = 0; j < 10; ++j) {
                if (!dp.count(mask ^ (1 << j))) {
                    continue;
                }
                ans = max(ans, i - dp[mask ^ (1 << j)]);
            }
            
            if (!dp.count(mask)) {
                dp[mask] = i;
            }
            else {
                ans = max(ans, i - dp[mask]);
            }
        }
        
        return ans;
    }
};