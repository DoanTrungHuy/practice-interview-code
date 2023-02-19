class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1), cnt(n, 1);
        int maxLen = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] and lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if (lis[i] == lis[j] + 1) {
                    cnt[i] += cnt[j];
                }
            }
            maxLen = max(maxLen, lis[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (lis[i] == maxLen) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};