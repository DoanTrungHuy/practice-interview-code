class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long best_val = 0;
        long long cnt_rep = 0;
        long long min_rep = INT_MAX;
        
        for (int num : nums) {
            best_val += 1LL*max(num, num ^ k);
            cnt_rep += (num ^ k) > num;
            min_rep = min(min_rep, (long long)abs(num - (num ^ k)));
        }
        
        if (cnt_rep & 1) {
            return best_val - min_rep;
        }
        
        return best_val;
    }
};