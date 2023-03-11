class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int subMax1[n];
        int subMax2[n];
        memset(subMax1, -1, sizeof(subMax1));
        memset(subMax2, -1, sizeof(subMax2));
        subMax1[0] = subMax1[0] = arr[0];
        
        int ans = arr[0];
        
        for (int i = 1; i < n; ++i) {
            subMax1[i] = max(subMax1[i - 1] + arr[i], arr[i]);
            subMax2[i] = max(subMax2[i - 1] + arr[i], arr[i]);
            
            if (i >= 2) {
                subMax2[i] = max(subMax2[i], subMax1[i - 2] + arr[i]);
            }
            
            ans = max({ans, subMax1[i], subMax2[i]});
        }
        
        return ans;
    }
};