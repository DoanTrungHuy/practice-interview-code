class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> hash, dp;
        hash['a'] = 1;
        hash['e'] = 2;
        hash['i'] = 3;
        hash['o'] = 4;
        hash['u'] = 5;
        dp[0] = -1;
        int mask = 0, ans = 0, n = s.size();
        
        for (int i = 0; i < n; ++i) {
            if (hash.count(s[i])) {
                mask ^= (1 << hash[s[i]]);
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