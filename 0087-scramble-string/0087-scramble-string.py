class Solution {
private:
    unordered_map<string, bool> dp;
    
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        
        if (s1 == s2) {
            return true;
        }
        
        if (n == 1) {
            return false;
        }
        
        string key = s1 + ',' + s2;
        
        if (dp.count(key)) {
            return dp[key];
        }
        
        for (int i = 1; i < n; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i))
               and isScramble(s1.substr(i), s2.substr(i))) {
                return dp[key] = true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(n - i))
               and isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return dp[key] = true;
            }
        }
        
        return dp[key] = false;
    }
};