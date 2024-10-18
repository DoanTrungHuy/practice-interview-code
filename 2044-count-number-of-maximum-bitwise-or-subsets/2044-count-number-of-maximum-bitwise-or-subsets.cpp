class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        const int n = nums.size();
        int max_or = 0, ans = 0;
    
        for (int num : nums) {
            max_or |= num;
        }
        
        int memo[n + 1][max_or + 1];
        memset(memo, -1, sizeof(memo));

        function<int(int, int)> dp = [&](int i, int current_or) -> int {
            if (i == n) {
                return current_or == max_or;
            }
            if (memo[i][current_or] != -1) {
                return memo[i][current_or];
            }
            return memo[i][current_or] = dp(i + 1, current_or | nums[i]) + dp(i + 1, current_or);
        };

        return dp(0, 0);
    }
};
