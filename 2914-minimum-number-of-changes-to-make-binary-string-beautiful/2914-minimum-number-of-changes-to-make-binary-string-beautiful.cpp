class Solution {
public:
    int minChanges(string s) {
        const int n = s.size();
        int res = 0;
        
        for (int i = 0; i < n; i += 2) {
            if (s[i] != s[i + 1]) {
                res++;
            }
        }
        
        return res;
    }
};