class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int n = nums.size();
        vector<int> pref(1), suff(1);
        
        for (int i = 0; i < n; ++i) {
            pref.push_back(pref.back() + nums[i]);
        }
        
        for (int i = n - 1; i >= 0; --i) {
            suff.push_back(suff.back() + nums[i]);
        }
        
        int ans = INT_MAX;
        
        for (int i = 0; i <= n; ++i) {
            int l = 0;
            int r = n - i;
            while (l <= r) {
                int m = (l + r) / 2;
                
                if (pref[m] + suff[i] == x) {
                    ans = min(ans, m + i);
                }
                
                if (pref[m] + suff[i] > x) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};