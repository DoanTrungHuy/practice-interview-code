class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        const int n = nums.size();
        int max_or = 0, ans = 0;
    
        for (int num : nums) {
            max_or |= num;
        }

        function<void(int, int)> dfs = [&](int i, int current_or) {
            if (i == n) {
                if (current_or == max_or) {
                    ++ans;
                }
                return;
            }

            dfs(i + 1, current_or | nums[i]);
            dfs(i + 1, current_or);
        };

        dfs(0, 0);
        return ans;
    }
};
