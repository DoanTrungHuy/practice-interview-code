class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[2][26] = {};
        const int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            cnt[0][s[i] - 'a']++;
            cnt[1][t[i] - 'a']++;
        }
        
        int ans = 0;
        
        for (int i = 0; i < 26; ++i) {
            ans += abs(cnt[0][i] - cnt[1][i]);
        }
        
        return ans / 2;
    }
};