class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int cntBit1 = 0;
            for (int num : nums) {
                if ((num >> i) & 1) {
                    cntBit1++;
                }
            }
            cntBit1 %= 3;
            if (cntBit1) {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};