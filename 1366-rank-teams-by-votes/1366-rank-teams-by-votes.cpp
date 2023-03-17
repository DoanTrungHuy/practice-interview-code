class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size(), m = votes[0].size();
        int cnt[m][26];
        memset(cnt, 0, sizeof(cnt));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cnt[j][votes[i][j] - 'A']++;
            }
        }
        
        string ans = votes[0];
        
        sort(ans.begin(), ans.end(), [&](char a, char b) {
            for (int j = 0; j < m; ++j) {
                if (cnt[j][a - 'A'] != cnt[j][b - 'A']) {
                    return cnt[j][a - 'A'] > cnt[j][b - 'A'];
                }
            }
            return a < b;
        });
        
        return ans;
    }
};