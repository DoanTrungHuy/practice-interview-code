class Solution {
public:
    vector<vector<int>> dp;
    int n;
    bool rec(vector<int> &nums, int s, int i = 0) {
        if (s < 0 || i >= n) {
            return false;
        }
        if (dp[s][i] != -1) {
            return dp[s][i];
        }
        if (s == 0) {
            return true;
        }
        return dp[s][i] = rec(nums, s - nums[i], i + 1) | rec(nums, s, i + 1);
    }
    bool canPartition(vector<int>& nums) {
        int s = 0;
        n = nums.size();
        for (int i = 0; i < n; ++i) {
            s += nums[i];
        }
        if (s & 1) {
            return false;
        }
        s /= 2;
        sort(nums.begin(), nums.end());
        dp.resize(s + 1, vector<int>(n, -1));
        return rec(nums, s);
    }
};