class Solution {
public:
    string decodeString(string s) {
        stack<int> st1;
        stack<string> st2;
        int num = 0;
        string res;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else if (isalpha(c)) {
                res += c;
            }
            else if (c == '[') {
                st1.push(num);
                st2.push(res);
                num = 0;
                res = "";
            }
            else {
                string tmp = res;
                for (int i = 0; i < st1.top() - 1; ++i) {
                    res += tmp;
                }
                res = st2.top() + res;
                st1.pop(), st2.pop();
            }
        }
        return res;
    }
};