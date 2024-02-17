class Solution {
private:
    vector<int> nums;
    int n;
    vector<unordered_map<int, int>> memo;
    
public:
    int dp(int i, int prev) {
        if (i == n) {
            return 0;
        }
        
        if (memo[i].count(prev)) {
            return memo[i][prev];
        }
        
        int ans = 0;
        // Case 1: when prev has not been increased:
        // Then we just consider whether nums[i] is one unit larger than prev?
        {
            if (nums[i] == prev + 1) {
                ans = max(ans, 1 + dp(i + 1, nums[i]));
            }
        }
        
        // Case 2: when I increase "prev", there will be two cases as follows:
        // One is the case where nums[i] is greater than 1 unit.
        // Second is the case where nums[i] + 1 can be equal to prev.
        // For example, if [1, 2, 3], when increasing at position 0, we get (prev = 2, nums[i] = 2), so we will ignore it and stop counting.
        {
            if (nums[i] + 1 == prev + 1) {
            ans = max(ans, 1 + dp(i + 1, nums[i] + 1));
            }
            if (nums[i] + 1 == prev) {
                ans = max(ans, dp(i + 1, nums[i] + 1));
            }
        }
        
        return memo[i][prev] = ans;
    }
    
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        this->n = nums.size();
        int ans = 0;
        memo.resize(n);
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, 1 + dp(i + 1, nums[i]));
        }
        for (int i = 0; i < n; ++i) {
            ans = max(ans, 1 + dp(i + 1, nums[i] + 1));
        }
        
        return ans;
    }
};