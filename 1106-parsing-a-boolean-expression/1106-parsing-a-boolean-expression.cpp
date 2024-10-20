class Solution {
public:
    int parse_or(vector<int> &bits) {
        int res = bits[0];
        int n = bits.size();
        for (int i = 1; i < n; ++i) {
            res |= bits[i];
        }
        return res;
    }
    
    int parse_and(vector<int> &bits) {
        int res = bits[0];
        int n = bits.size();
        for (int i = 1; i < n; ++i) {
            res &= bits[i];
        }
        return res;
    }
    
    bool parseBoolExpr(string expression) {
        stack<char> st;
        
        for (char c : expression) {
            if (c == ',' or c == '(') {
                continue;
            }
            if (c == ')') {
                vector<int> bits;
                while (st.top() != '&' and st.top() != '|' and st.top() != '!') {
                    char dummy = st.top();
                    st.pop();
                    if (dummy == 't') {
                        bits.push_back(1);
                    }
                    if (dummy == 'f') {
                        bits.push_back(0);
                    }
                }
                char op = st.top();
                st.pop();
                if (op == '&') {
                    st.push(parse_and(bits) ? 't' : 'f');
                }
                else if (op == '|') {
                    st.push(parse_or(bits) ? 't' : 'f');
                }
                else if (op == '!') {
                    st.push(!bits[0] ? 't' : 'f');
                }
            }
            else {
                st.push(c);
            }
        }
        
        return st.top() == 't';
    }
};