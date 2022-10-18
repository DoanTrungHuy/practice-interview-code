class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while (--n) {
            string tmp;
            int cnt = 1, n = ans.size();
            char ptr = ans[0];
            
            for (int i = 1; i < n; ++i) {
                if (ptr == ans[i]) {
                    cnt++;
                } else {
                    tmp += to_string(cnt);
                    tmp += ptr;
                    cnt = 1, ptr = ans[i];
                }
            }
            
            tmp += to_string(cnt);
            tmp += ptr;
            
            ans = tmp;
        }
        
        return ans;
    }
};