int memo[2][20][20];

class Solution {
private:
    vector<int> nums;
    int n;
    
public:
    int dp(int p, int i, int j) {
        if (i > j) {
            return 0;
        }
        if (memo[p][i][j] != -1) {
            return memo[p][i][j];
        }
        if (!p) {
            return memo[p][i][j] = max(
                nums[i] + dp(!p, i + 1, j),
                nums[j] + dp(!p, i, j - 1)
            );
        }
        else {
            return memo[p][i][j] = min(
                -nums[i] + dp(!p, i + 1, j),
                -nums[j] + dp(!p, i, j - 1)
            );
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        this->nums = nums;
        this->n = nums.size();
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, n - 1) >= 0;
    }
};