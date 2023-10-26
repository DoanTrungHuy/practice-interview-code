const int MOD = 1e9 + 7;

class Solution {
private:
    vector<int> nums;
    set<int> us;
    unordered_map<int, int> dp;
    
public:
    
    int dfs(int i, int s) {
        if (dp.count(s)) {
            return dp[s];
        }
        int ans = 1;
        for (int j = 0; j < (int)nums.size(); ++j) {
            if (s % nums[j] != 0) {
                continue;
            }
            if (us.count(s / nums[j])) {
                ans = (ans + (1LL * dfs(j, s / nums[j]) * dfs(j, nums[j])) % MOD) % MOD;
            }
        }
        return dp[s] = ans;
    }
    
    int numFactoredBinaryTrees(vector<int>& nums) {
        for (int num : nums) {
            us.insert(num);
        }
        
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        this->nums = nums;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            ans = (ans + dfs(i, nums[i])) % MOD;
        }
        
        return ans;
    }
};