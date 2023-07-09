int memo[1001];

class Solution {
private:
    int n;
    vector<int> nums;
    int target;
    
public:
    int dp(int i) {
        if (i == n - 1) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int ans = INT_MIN;
        for (int j = i + 1; j < n; ++j) {
            if (-target <= (nums[j] - nums[i]) and (nums[j] - nums[i]) <= target) {
                ans = max(ans, 1 + dp(j));
            }
        }
        return memo[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        this->n = nums.size();
        memset(memo, -1, sizeof(memo));
        this->nums = nums, this->target = target;
        return dp(0) < 0 ? -1 : dp(0);
    }
};