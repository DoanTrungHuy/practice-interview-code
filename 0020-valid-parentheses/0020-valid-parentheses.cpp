class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        unordered_map<char, char> um;
        um['('] = ')';
        um['['] = ']';
        um['{'] = '}';

        for (int i = 0; i < n; ++i) {
            if (um.find(s[i]) != um.end()) {
                st.push(s[i]);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                char topSt = um[st.top()];
                st.pop();
                if (topSt != s[i]) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};