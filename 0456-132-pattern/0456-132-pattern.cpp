class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int n = nums.size();
        int s3 = INT_MIN;
        stack<int> st;
        
        for (int i = n - 1; i >= 0; --i) {
            if (s3 > nums[i]) {
                return true;
            }
            while (!st.empty() and nums[i] > st.top()) {
                s3 = st.top();
                st.pop();
            }
            st.push(nums[i]);    
        }
        
        return false;
    }
};