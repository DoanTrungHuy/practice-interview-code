class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        const int n = nums.size();
        int max_num = 0;
        
        for (int i = 0; i < n; ++i) {
            max_num |= nums[i];
        }
        
        int MB = (1 << n) - 1;
        int ans = 0;
        
        for (int mask = 0; mask <= MB; ++mask) {
            int num = 0;
            for (int bit = 0; bit < n; ++bit) {
                if (mask & (1 << bit)) {
                    num |= nums[bit];
                }
            }
            ans += num == max_num;
        }
        
        return ans;
    }
};