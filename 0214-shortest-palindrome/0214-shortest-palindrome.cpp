class Solution {
public:
    string shortestPalindrome(string s) {
        const long long base = 4;
        const long long mod = 1e9 + 13;
        
        long long p1 = 0;
        long long p2 = 0;
        long long dummy_base = 1;
        int p = 0;
        const int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            
            p1 = ((c - 'a' + 1) + p1*base) % mod;
            p2 = ((c - 'a' + 1)*dummy_base + p2) % mod;
            dummy_base = (dummy_base * base) % mod;
            
            if (p1 == p2) {
                p = i;
            }
        }
        
        string t = s.substr(min(p + 1, n));
        reverse(t.begin(), t.end());
        
        return t + s;
    }
};