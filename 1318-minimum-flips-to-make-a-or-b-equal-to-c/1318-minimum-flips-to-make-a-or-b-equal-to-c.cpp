class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int aBit = (1 << i) & a;
            int bBit = (1 << i) & b;
            int cBit = (1 << i) & c;

            if (cBit == 0) {
                res += (aBit != 0) + (bBit != 0);
            }
            else {
                res += (aBit == 0 and bBit == 0);
            }
        }
        
        return res;
    }
};