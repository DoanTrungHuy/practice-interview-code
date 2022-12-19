class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        int dp[11][1 << 10][3];
        memset(dp, 0, sizeof(dp));
        int total = n;
        vector<int> nums;
        while (n > 0) {
            nums.push_back(n % 10);
            n /= 10;
        }
        reverse(nums.begin(), nums.end());
        for (int d = 1; d <= 9; ++d) {
            int states = 0;
            if (d > nums[0]) {
                states = 2;
            }
            else if (d == nums[0]) {
                states = 1;
            }
            dp[1][1 << d][states]++;
        }
        int sz = nums.size();
        for (int i = 1; i < sz; ++i) {
            for (int mask = 1; mask < (1 << 10); ++mask) {
                for (int states = 0; states <= 2; ++states) {
                    if (dp[i][mask][states] == 0) {
                        continue;
                    }
                    for (int d = 0; d <= 9; ++d) {
                        if (mask & (1 << d)) {
                            continue;
                        }
                        int newStates = states;
                        int newMask = (mask | (1 << d));
                        if (states == 1) {
                            if (d > nums[i]) {
                                newStates = 2;
                            }
                            else if (d < nums[i]) {
                                newStates = 0;
                            }
                        }
                        dp[i + 1][newMask][newStates] += dp[i][mask][states];
                    }
                }
            }
        }
        int negAns = 0;
        for (int i = 1; i <= sz; ++i) {
            for (int mask = 1; mask < (1 << 10); ++mask) {
                int szStates = (i == sz) ? 1 : 2;
                for (int states = 0; states <= szStates; ++states) {
                    negAns += dp[i][mask][states];
                }
            } 
        }
        return total - negAns;
    }
};