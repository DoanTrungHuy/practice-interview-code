class Solution {
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<vector<int>> scd;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            scd.push_back({s[i], e[i], p[i]});
        }
        sort(scd.begin(), scd.end());
        map<int, int> mm;
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            auto it = mm.lower_bound(scd[i][1]);
            dp[i] = max(dp[i + 1], it->second + scd[i][2]);
            mm[scd[i][0]] = dp[i];
        }
        return dp[0];
    }
};