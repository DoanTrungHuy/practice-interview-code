class Solution {
private:
    int n;
    
public:
    int dfs(vector<int>& nums, int target, int i) {
        if (i == n) {
            return target == 0;
        }
        int cnt = 0;
        cnt += dfs(nums, target - nums[i], i + 1);
        cnt += dfs(nums, target + nums[i], i + 1);
        return cnt;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        return dfs(nums, target, 0);
    }
};