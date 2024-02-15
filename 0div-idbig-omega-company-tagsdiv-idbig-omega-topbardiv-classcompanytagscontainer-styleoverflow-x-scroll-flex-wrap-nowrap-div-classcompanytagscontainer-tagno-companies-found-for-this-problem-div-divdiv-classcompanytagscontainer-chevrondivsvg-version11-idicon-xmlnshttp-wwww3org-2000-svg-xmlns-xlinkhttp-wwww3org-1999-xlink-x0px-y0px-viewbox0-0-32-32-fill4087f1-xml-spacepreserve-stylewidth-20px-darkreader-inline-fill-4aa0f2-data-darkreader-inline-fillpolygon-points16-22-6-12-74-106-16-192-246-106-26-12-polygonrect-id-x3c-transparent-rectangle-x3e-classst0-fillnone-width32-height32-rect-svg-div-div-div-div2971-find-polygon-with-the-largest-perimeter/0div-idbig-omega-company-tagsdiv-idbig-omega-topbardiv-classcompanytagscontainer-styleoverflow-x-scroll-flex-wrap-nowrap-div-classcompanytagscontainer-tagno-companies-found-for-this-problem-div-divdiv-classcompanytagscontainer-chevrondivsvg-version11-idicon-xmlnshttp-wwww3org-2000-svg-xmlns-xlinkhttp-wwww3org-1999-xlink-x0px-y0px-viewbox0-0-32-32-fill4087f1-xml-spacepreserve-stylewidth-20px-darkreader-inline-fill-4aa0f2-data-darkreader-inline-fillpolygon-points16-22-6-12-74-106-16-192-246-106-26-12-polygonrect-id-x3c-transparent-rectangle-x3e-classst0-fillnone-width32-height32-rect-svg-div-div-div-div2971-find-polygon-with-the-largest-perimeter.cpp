class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        long long pref[n + 1];     
        memset(pref, 0, sizeof pref);
        
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }
        
        for (int i = n - 1; i >= 0; --i) {
            if (pref[i] > nums[i]) {
                return pref[i + 1];
            }
        }
        
        return -1;
    }
};