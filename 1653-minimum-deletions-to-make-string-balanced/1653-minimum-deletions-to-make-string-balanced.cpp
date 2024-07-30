class Solution {
public:
    int minimumDeletions(string s) {
        int cnt = 0;
        stack<int> st;
        
        for (char c : s) {
            if (st.size() && st.top() > c) {
                st.pop();
                cnt++;
            }
            else {
                st.push(c);
            }
        }
        
        return cnt;
    }
};