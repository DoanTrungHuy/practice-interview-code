class Solution {
public:
    int uniqueLetterString(string s) {
        const int n = s.size();
        int ans = 0;
        const int MOD = 1e9 + 7;
        
        for (int i = 0, l = i, r = i; i < n; ++i) {
            for (l = i - 1; l >= 0 && s[i] != s[l]; --l);
            for (r = i + 1; r < n && s[i] != s[r]; ++r);
            ans += ((i - l)*(r - i)) % MOD;
        }
        
        return ans;
    }
};