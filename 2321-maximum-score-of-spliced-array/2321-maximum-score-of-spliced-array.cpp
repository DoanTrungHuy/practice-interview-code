class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        int sum1 = 0, sum2 = 0;
        
        for (int i = 0; i < n; ++i) {
            sum1 += nums1[i];
            sum2 += nums2[i];
        }
        
        int max1 = 0, max2 = 0;
        int cur1 = 0, cur2 = 0;
        
        for (int i = 0; i < n; ++i) {
            cur1 = max(0, cur1 + nums2[i] - nums1[i]);
            cur2 = max(0, cur2 + nums1[i] - nums2[i]);
            max1 = max(max1, cur1);
            max2 = max(max2, cur2);
        }
        
        return max({sum1, sum2, sum1 + max1, sum2 + max2});
    }
};