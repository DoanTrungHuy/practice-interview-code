class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        stack<int> st;
        const int n = target.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!st.empty() && st.top() >= target[i]) {
                ans += st.top() - target[i];
                st.pop();
            }
            st.push(target[i]);
        }
        
        ans += st.top();
        
        return ans;
    }
};