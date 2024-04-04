class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int cnt_curr_char = 0;
        for (char c : s) {
            if (c == '(') {
                ++cnt_curr_char;
            }
            else if (c == ')') {
                --cnt_curr_char;
            }
            ans = max(ans, cnt_curr_char);
        }
        return ans;
    }
};