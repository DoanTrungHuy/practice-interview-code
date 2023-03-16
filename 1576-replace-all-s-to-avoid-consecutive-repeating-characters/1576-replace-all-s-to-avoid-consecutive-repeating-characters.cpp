class Solution {
public:
    string modifyString(string s) {
        const int n = s.size();
        
        if (s[0] == '?') {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c != s[1]) {
                    s[0] = c;
                    break;
                }
            }
        }
        
        if (s[n - 1] == '?') {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c != s[n - 2]) {
                    s[n - 1] = c;
                    break;
                }
            }
        }
        
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == '?') {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (s[i - 1] != c and c != s[i + 1]) {
                        s[i] = c;
                        break;
                    }
                }
            }
        }
        
        return s;
    }
};