class Solution {
private:
    int n;
    
public:
    int memo[1001];
    
    int dp(string &s, int i) {
        if (i == n) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int ans = 1e9;
        int cnt[26] = {};
        for (int j = i; j < n; ++j) {
            int mi = 1e9, mx = 0;
            cnt[s[j] - 'a']++;
            for (int c = 0; c < 26; ++c) {
                if (cnt[c] == 0) {
                    continue;
                }
                mi = min(mi, cnt[c]);
                mx = max(mx, cnt[c]);
            }
            if (mi == mx) {
                ans = min(ans, 1 + dp(s, j + 1));
            }
        }
        return memo[i] = ans;
    }
    
    int minimumSubstringsInPartition(string s) {
        memset(memo, -1, sizeof(memo));
        n = s.size();
        return dp(s, 0);
    }
};