class Solution {
private:
    int n;
    int numSlots;
    vector<int> nums;
    int memo[18][1 << 18];

public:
    int dp(int i, int mask) {
        if (i == n) {
            return 0;
        }
        if (memo[i][mask] != -1) {
            return memo[i][mask];
        }
        int ans = INT_MIN;
        for (int j = 0; j < numSlots; ++j) {
            int slot1 = j;
            int slot2 = j + numSlots;
            if (!(mask & (1 << slot1))) {
                ans = max(ans, ((j + 1) & nums[i]) + dp(i + 1, mask | (1 << slot1)));
            }
            if (!(mask & (1 << slot2))) {
                ans = max(ans, ((j + 1) & nums[i]) + dp(i + 1, mask | (1 << slot2)));
            }
        }
        return memo[i][mask] = ans;
    }

    int maximumANDSum(vector<int>& nums, int numSlots) {
        this->n = nums.size();
        this->numSlots = numSlots;
        this->nums = nums;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0);
    }
};
