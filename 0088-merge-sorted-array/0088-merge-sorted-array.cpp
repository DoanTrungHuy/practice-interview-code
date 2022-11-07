class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sz = nums1.size();
        while (n--) {
            nums1[--sz] = nums2[n];
        }
        sort(nums1.begin(), nums1.end());
    }
};