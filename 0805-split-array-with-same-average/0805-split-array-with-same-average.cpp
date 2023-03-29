class Solution {
public:
    unordered_map<int, unordered_set<double>> masking(vector<int> nums) {
        int n = nums.size();
        int m = (1 << n);
        unordered_map<int, unordered_set<double>> ans;
        
        for (int mask = 0; mask < m; ++mask) {
            int sum = 0, cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += nums[i];
                }
            }
            ans[cnt].insert(sum);
        }
        
        return ans;
    }
    
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int m = n >> 1;
        vector<int> nums1(nums.begin(), nums.begin() + m);
        vector<int> nums2(nums.begin() + m, nums.end());
        unordered_map<int, unordered_set<double>> allSubset1 = masking(nums1);
        unordered_map<int, unordered_set<double>> allSubset2 = masking(nums2);
        
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        
        double sum = accumulate(nums.begin(), nums.end(), 0);
        
        for (int len1 = 0; len1 <= sz1; ++len1) {
            for (double sum1 : allSubset1[len1]) {
                for (int len2 = 0; len2 <= sz2; ++len2) {
                    if (len1 + len2 == 0 or len1 + len2 == n) {
                        continue;
                    }
                    
                    double sum2 = sum * (len1 + len2) / n - sum1; 
                    
                    if (allSubset2[len2].count(sum2)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};