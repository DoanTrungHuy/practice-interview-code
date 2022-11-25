class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n <= k) {
            return "0";
        }
        if (k == 0) {
            return num;
        }
        stack<char> st;
        st.push(num[0]);
        for (int i = 1; i < n; ++i) {
            while (k > 0 and !st.empty() and st.top() > num[i]) {
                st.pop();
                --k;
            }
            st.push(num[i]);
            if (st.size() == 1 and num[i] == '0') {
                st.pop();
            }
        }
        while (k > 0 and !st.empty()) {
            st.pop();
            --k;
        }
        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        if (res.size() == 0) {
            return "0";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};