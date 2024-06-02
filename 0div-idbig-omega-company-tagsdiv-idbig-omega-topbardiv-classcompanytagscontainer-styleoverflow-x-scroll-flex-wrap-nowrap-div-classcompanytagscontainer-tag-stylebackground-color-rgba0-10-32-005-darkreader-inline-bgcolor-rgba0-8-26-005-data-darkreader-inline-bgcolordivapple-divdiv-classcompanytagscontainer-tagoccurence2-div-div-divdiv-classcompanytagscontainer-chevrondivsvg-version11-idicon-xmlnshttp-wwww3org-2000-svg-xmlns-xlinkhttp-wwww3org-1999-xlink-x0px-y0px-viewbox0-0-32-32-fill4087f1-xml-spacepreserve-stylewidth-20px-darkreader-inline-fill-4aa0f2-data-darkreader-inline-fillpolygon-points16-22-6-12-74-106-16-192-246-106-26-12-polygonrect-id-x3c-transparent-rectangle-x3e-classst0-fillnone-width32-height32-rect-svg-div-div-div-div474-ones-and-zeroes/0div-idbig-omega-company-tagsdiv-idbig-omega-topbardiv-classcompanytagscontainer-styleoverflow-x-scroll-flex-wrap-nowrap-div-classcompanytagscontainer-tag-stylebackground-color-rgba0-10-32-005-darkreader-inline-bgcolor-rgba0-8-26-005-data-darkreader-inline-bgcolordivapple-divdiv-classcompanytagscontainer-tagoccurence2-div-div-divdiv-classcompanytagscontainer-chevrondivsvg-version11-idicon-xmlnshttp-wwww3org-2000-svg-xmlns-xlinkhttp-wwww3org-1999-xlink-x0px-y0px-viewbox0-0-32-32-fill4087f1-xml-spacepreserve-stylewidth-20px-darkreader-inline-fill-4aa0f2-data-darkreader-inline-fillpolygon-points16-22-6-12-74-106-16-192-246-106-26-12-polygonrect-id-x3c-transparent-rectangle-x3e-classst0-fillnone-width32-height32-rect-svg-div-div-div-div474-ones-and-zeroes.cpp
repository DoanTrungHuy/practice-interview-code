int memo[602][101][101];

class Solution {
private:
    vector<string> strs;
    vector<vector<int>> vp;
    
public:
    int dp(int i, int c0, int c1) {
        if (i == (int)vp.size()) {
            return 0;
        }
        if (memo[i][c0][c1] != -1) {
            return memo[i][c0][c1];
        }
        int ans = dp(i + 1, c0, c1);
        if (c0 - vp[i][0] >= 0 and c1 - vp[i][1] >= 0) {
            ans = max(ans, 1 + dp(i + 1, c0 - vp[i][0], c1 - vp[i][1]));
        }
        return memo[i][c0][c1] = ans;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        this->strs = strs;
        for (string s : strs) {
            int cnt0 = 0;
            for (char c : s) {
                cnt0 += c == '0';
            }
            vp.push_back({cnt0, (int)s.size() - cnt0});
        }
        memset(memo, -1, sizeof(memo));
        return dp(0, m, n);
    }
};