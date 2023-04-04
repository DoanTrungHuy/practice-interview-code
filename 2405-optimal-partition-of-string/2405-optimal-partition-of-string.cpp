const int maxn = 1e5 + 1;
int dp[maxn];
int n;

class Solution {
public:
    int dfs(string &s, int i) {
        if (i == n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int cnt[26] = {};
        int ans = INT_MAX;
        for (int j = i; j < n; ++j) {
            if (cnt[s[j] - 'a'] == 0) {
                cnt[s[j] - 'a']++;
                ans = min(ans, 1 + dfs(s, j + 1));
            }
            else {
                break;
            }
        }
        return dp[i] = ans;
    }
    int partitionString(string s) {
        memset(dp, -1, sizeof(dp));
        n = s.size();
        return dfs(s, 0);
    }
};