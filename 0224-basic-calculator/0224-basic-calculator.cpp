class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        st.push(1);
        int res = 0;
        int num = 0;
        int sgn = 1;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            else if (c == '-' or c == '+') {
                res += num * sgn * st.top();
                sgn = c == '-' ? -1 : 1;
                num = 0;
            }
            else if (c == '(') {
                st.push(sgn * st.top());
                sgn = 1;
            }
            else if (c == ')') {
                res += num * sgn * st.top();
                num = 0;
                st.pop();
            }
        }
        res += num * sgn * st.top();
        return res;
    }
};