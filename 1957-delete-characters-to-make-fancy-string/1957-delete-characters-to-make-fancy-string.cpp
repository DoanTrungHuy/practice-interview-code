class Solution {
public:
    string makeFancyString(string s) {
        const int n = s.size();
        int curr_cnt = 0;
        char c = '0';
        string ans;
        
        for (int i = 0; i < n; ++i) {
            if (curr_cnt == -1 || c == s[i]) {
                curr_cnt++;
            }
            else {
                curr_cnt = 1;
            }
            if (curr_cnt <= 2) {
                ans += s[i];
            }
            c = s[i];
        }
        
        return ans;
    }
};