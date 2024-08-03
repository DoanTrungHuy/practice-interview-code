class Solution {
public:
    long long count_min_sub(vector<int> arr) {
        const int n = arr.size();
        stack<int> st;
        vector<long long> left(n, -1), right(n, n);
        
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while (st.size()) {
            st.pop();
        }
        
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        long long ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int left_count = i - left[i];
            int right_count = right[i] - i;
            ans = (ans + (long long)arr[i] * left_count * right_count);
        }
        
        return ans;
    }
    
    long long count_max_sub(vector<int> arr) {
        const int n = arr.size();
        stack<int> st;
        vector<long long> left(n, -1), right(n, n);
        
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while (st.size()) {
            st.pop();
        }
        
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        long long ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int left_count = i - left[i];
            int right_count = right[i] - i;
            ans = (ans + (long long)arr[i] * left_count * right_count);
        }
        
        return ans;
    }
    
    long long subArrayRanges(vector<int>& arr) {
        return count_max_sub(arr) - count_min_sub(arr);
    }
};