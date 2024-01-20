class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        arr.insert(arr.begin(), 0);
        stack<int> st;
        st.push(0);
        int n = arr.size();
        vector<int> dp(n, 0);
        const int mod = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            while (!st.empty() and arr[st.top()] > arr[i]) {
                st.pop();
            }
            int j = st.top();
            dp[i] = dp[j] + (i - j) * arr[i];
            st.push(i);
        }
        int res = 0;
        for (int i = 1; i < n; ++i) {
            res = (res + dp[i]) % mod;
        }
        return res;
    }
};