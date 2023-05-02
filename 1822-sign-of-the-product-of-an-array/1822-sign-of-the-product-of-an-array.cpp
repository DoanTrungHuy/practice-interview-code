class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cntNeg = 0;
        for (int num : nums) {
            if (num == 0) {
                return 0;
            }
            cntNeg += num < 0;
        }
        return cntNeg % 2 == 0 ? 1 : -1;
    }
};