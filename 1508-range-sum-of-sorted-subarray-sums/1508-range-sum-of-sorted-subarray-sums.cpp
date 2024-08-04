class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        vector<int> all_sum;
        
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (int j = i; j >= 0; --j) {
                s += nums[j];
                all_sum.push_back(s);
            }
        }
        
        sort(all_sum.begin(), all_sum.end());
        
        int ans = 0;
        const int MOD = 1e9 + 7;
        l--;
        r--;
        
        for (int i = l; i <= r; ++i) {
            ans = (ans + all_sum[i]) % MOD;
        }
        
        return ans;
    }
};