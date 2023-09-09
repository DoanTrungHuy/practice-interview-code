class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                while (!st.empty() and nums[st.top()] < nums[j]) {
                    ans[st.top()] = nums[j];
                    st.pop();
                }
                st.push(j);
            }
        }
        
        return ans;
    }
};