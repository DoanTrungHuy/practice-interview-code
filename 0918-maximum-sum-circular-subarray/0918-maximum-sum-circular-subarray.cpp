class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int oo = 1e5;
        int minSub = oo;
        int ansMin = oo;
        int maxSub = -oo;
        int ansMax = -oo;
        int s = 0;
        for (int num : nums) {
            minSub = min(num, minSub + num);
            ansMin = min(ansMin, minSub);
            maxSub = max(num, maxSub + num);
            ansMax = max(ansMax, maxSub);
            s += num;
        }
        if (ansMax < 0) {
            return ansMax;
        }
        return max(s - ansMin, ansMax);
    }
};