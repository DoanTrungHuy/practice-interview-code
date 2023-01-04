class Solution {
public:
    int dp[11][2][2][1 << 10];
    int sz;
    string nums;
    
    int dfs(int i, bool tight, bool hasRep, int mask) {
        if (i == sz) {
            return hasRep;
        }
        if (dp[i][tight][hasRep][mask] != -1) {
            return dp[i][tight][hasRep][mask];
        }
        int limit = tight ? nums[i] - '0' : 9;
        int ans = 0;
        for (int d = 0; d <= limit; ++d) {
            bool newTight = tight and d == nums[i] - '0';
            bool newRep = hasRep or mask & (1 << d); 
            int newMask = d == 0 and mask == 0 ? mask : mask | (1 << d);
            ans += dfs(i + 1, newTight, newRep, newMask);
        }
        return dp[i][tight][hasRep][mask] = ans;
    }
    
    int numDupDigitsAtMostN(int n) {
        memset(dp, -1, sizeof(dp));
        nums = to_string(n);
        sz = nums.size();
        return dfs(0, true, false, 0);
    }
};