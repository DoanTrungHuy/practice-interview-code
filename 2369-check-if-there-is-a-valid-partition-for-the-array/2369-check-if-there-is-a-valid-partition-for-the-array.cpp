const int MAXN = 1e5 + 1;
int memo[MAXN];

class Solution {
private:
    vector<int> nums;
    
public:
    int dp(int i) {
        if (i == -1) {
            return 1;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int ans = 0;
        if (i > 0 and nums[i] == nums[i - 1]) {
            ans |= dp(i - 2);
        }
        if (i > 1 and nums[i] == nums[i - 1] and nums[i - 1] == nums[i - 2]) {
            ans |= dp(i - 3);
        }
        if (i > 1 and nums[i] == nums[i - 1] + 1 and nums[i - 1] == nums[i - 2] + 1) {
            ans |= dp(i - 3);
        }
        return memo[i] = ans;
    }
    
    bool validPartition(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        memset(memo, -1, sizeof(memo));
        return dp(n - 1);
    }
};