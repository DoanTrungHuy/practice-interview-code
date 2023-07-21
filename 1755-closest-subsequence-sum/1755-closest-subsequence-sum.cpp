class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        set<int> sub_sums_case1, sub_sums_case2;
        int n = nums.size();
        int mid = n / 2;
        
        for (int mask = 0; mask < (1 << mid); ++mask) {
            int sum = 0;
            for (int i = 0; i < mid; ++i) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                }
            }
            sub_sums_case1.insert(sum);
        }
        
        for (int mask = 0; mask < (1 << (n - mid)); ++mask) {
            int sum = 0;
            for (int i = 0; i < n - mid; ++i) {
                if (mask & (1 << i)) {
                    sum += nums[i + mid];
                }
            }
            sub_sums_case2.insert(sum);
        }
        
        int diff = INT_MAX;
        
        for (int num1 : sub_sums_case1) {
            auto it = sub_sums_case2.lower_bound(goal - num1);
 
            if (it != sub_sums_case2.end()) {
                diff = min(diff, abs(goal - num1 - *it));
            }
            if (it != sub_sums_case2.begin()) {
                it--;
            }
            if (it != sub_sums_case2.end()) {
                diff = min(diff, abs(goal - num1 - *it));
            }
        }
        
        return diff;
    }
};