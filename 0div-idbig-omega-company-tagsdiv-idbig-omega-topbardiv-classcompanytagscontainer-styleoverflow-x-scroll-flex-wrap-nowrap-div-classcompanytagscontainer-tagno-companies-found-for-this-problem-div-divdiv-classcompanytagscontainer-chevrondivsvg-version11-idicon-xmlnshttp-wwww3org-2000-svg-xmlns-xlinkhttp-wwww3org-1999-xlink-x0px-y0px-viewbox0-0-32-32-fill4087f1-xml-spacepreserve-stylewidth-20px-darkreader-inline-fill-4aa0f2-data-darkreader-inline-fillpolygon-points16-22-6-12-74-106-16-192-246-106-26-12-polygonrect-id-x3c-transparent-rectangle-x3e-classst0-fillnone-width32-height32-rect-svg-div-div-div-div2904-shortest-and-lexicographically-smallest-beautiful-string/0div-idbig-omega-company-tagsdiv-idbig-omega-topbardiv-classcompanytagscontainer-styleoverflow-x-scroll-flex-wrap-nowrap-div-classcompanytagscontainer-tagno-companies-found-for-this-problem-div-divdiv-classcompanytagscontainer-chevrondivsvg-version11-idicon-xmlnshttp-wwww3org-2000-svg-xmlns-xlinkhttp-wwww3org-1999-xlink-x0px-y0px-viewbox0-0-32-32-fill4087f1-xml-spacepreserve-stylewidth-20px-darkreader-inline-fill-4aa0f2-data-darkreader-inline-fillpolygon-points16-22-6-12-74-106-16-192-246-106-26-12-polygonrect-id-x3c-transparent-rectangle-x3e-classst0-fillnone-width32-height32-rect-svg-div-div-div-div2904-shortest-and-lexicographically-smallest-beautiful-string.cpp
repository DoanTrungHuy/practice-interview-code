class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        const int n = s.size();
        int j = 0;
        int cnt_one = 0;
        int ans = INT_MAX;
        string t = "";
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                cnt_one++;
            }
            
            while (j <= i and cnt_one > k) {
                if (s[j] == '1') {
                    cnt_one--;
                }
                j++;
            }
            
            if (cnt_one == k) {
                while (j <= i and s[j] == '0') {
                    j++;
                }
                if (ans >= i - j + 1) {
                    ans = i - j + 1;
                    if (t == "" or t.size() > ans) {
                        t = s.substr(j, i - j + 1);
                    }
                    else {
                        t = min(t, s.substr(j, i - j + 1));
                    }
                }
            }
        }
        
        if (ans == INT_MAX) {
            return "";
        }
        
        return t;
    }
};