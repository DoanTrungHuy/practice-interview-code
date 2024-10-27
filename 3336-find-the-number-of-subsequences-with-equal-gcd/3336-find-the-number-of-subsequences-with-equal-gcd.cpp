const int MOD = 1e9 + 7;

class Solution {
public:
    int memo[201][201][201];

    int dp(int i, int gc1, int gc2, vector<int>& nums) {
        if(i == nums.size()) {
            return gc1 == gc2;
        }

        if(memo[i][gc1][gc2] != -1) {
            return memo[i][gc1][gc2];
        }

        int v1 = dp(i + 1, __gcd(gc1, nums[i]), gc2, nums);
        int v2 = dp(i + 1, gc1, __gcd(gc2, nums[i]), nums);
        int v3 = dp(i + 1, gc1, gc2, nums);
        
        return memo[i][gc1][gc2] = (1LL * v1 + v2 + v3) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, 0, nums) - 1;
    }
};