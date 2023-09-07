int memo[40001][3];

class Solution {
private:
    vector<int> nums;
    
public:
    int dp(int i, int s) {
        if (i == (int)nums.size()) {
            if (s == 0) {
                return 0;
            }
            return -1e6;
        }
        if (memo[i][s] != -1) {
            return memo[i][s];
        }
        int op1 = dp(i + 1, (s + nums[i]) % 3) + nums[i];
        int op2 = dp(i + 1, s);
        return memo[i][s] = max(op1, op2);
    }
    
    int maxSumDivThree(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        this->nums = nums;
        return dp(0, 0);
    }
};