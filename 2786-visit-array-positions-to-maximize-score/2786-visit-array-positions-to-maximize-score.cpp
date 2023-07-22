class Solution {
private:
    vector<int> nums;
    int n, x;
    
public:
    long long memo[100005][2];
    
    long long dp(int i, bool isOdd) {
        if (i == n) {
            return 0;
        }
        
        if (memo[i][isOdd] != -1) {
            return memo[i][isOdd];
        }
        
        long long res1 = dp(i + 1, isOdd);
        
        long long res2;
        
        
        if (i == 0) {
            res2 = nums[i] + dp(i + 1, isOdd);
        }
        else if ((nums[i]&1 and isOdd) or ((nums[i]&1)^1 and isOdd^1)) {
            res2 = dp(i + 1, isOdd) + nums[i];
        }
        else {
            res2 = dp(i + 1, isOdd^1) + nums[i] - x;
        }
        
        return memo[i][isOdd] = max(res1, res2);
    }
    
    long long maxScore(vector<int>& nums, int x) {
        memset(memo, -1, sizeof(memo));
        this->nums = nums;
        this->x = x;
        this-> n = nums.size();
        
        return dp(0, nums[0]&1);
    }
};