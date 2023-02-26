class Solution {
public:
    string handleBackspace(string s) {
        string ans;
        for (char c : s) {
            if (c == '#') {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            }
            else {
                ans.push_back(c);
            }
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        return handleBackspace(s) == handleBackspace(t);
    }
};