class Solution {
public:
    int countHomogenous(string s) {
        const int MOD = 1e9 + 7;
        const int n = s.size();
        int cnt = 1, ans = 1;
        char c = s[0];
        
        for (int i = 1; i < n; ++i) {
            if (c == s[i]) {
                cnt++;
            }
            else {
                c = s[i];
                cnt = 1;
            }
            ans = (ans + cnt) % MOD;
        }
        
        return ans;
    }
};