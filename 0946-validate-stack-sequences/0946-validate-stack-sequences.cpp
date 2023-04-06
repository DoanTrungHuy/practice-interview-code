class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        const int n = popped.size();
        
        for (int num : pushed) {
            st.push(num);
            while (!st.empty() and j < n and st.top() == popped[j]) {
                st.pop(), j++;
            }
        }
        
        return j == n;
    }
};