class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string a, const string b) {
            return a.size() < b.size();
        });
        
        const int n = words.size();
        int dp[n];
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                int sz[2] = {(int)words[j].size(), (int)words[i].size()};
                if (sz[0] + 1 != sz[1]) {
                    continue;
                }
                int p = 0;
                for (char c : words[i]) {
                    if (words[j][p] == c) {
                        p++;
                    }
                } 
                if (p != sz[0]) {
                    continue;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};