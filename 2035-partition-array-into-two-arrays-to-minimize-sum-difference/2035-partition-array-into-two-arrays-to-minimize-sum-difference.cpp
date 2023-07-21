class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;
        vector<vector<int>> arr1_diff_sub(m + 1);
        
        for (int mask = 0; mask < (1 << m); ++mask) {
            int sum = 0;
            int len = 0;
            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    len += 1;
                    sum += nums[i];
                }
                else {
                    sum -= nums[i];
                }
            }
            arr1_diff_sub[len].push_back(sum);
        }
        
        for (int len = 0; len <= m; ++len) {
            sort(arr1_diff_sub[len].begin(), arr1_diff_sub[len].end());
        }
        
        int minDiff = INT_MAX;
        
        for (int mask = 0; mask < (1 << (n - m)); ++mask) {
            int sum = 0;
            int len = 0;
            
            for (int i = 0; i < (n - m); ++i) {
                if (mask & (1 << i)) {
                    len += 1;
                    sum += nums[i + m];
                }
                else {
                    sum -= nums[i + m];
                }
            }
            
            int diff2 = sum;
            
            auto it = lower_bound(arr1_diff_sub[m - len].begin(), arr1_diff_sub[m - len].end(), -diff2);
            
            if (it != arr1_diff_sub[m - len].end()) {
                minDiff = min(minDiff, abs(diff2 + *it));
            }
            
            if (it != arr1_diff_sub[m - len].begin()) {
                minDiff = min(minDiff, abs(diff2 + *prev(it)));
            }
        }
        
        return minDiff;
    }
};