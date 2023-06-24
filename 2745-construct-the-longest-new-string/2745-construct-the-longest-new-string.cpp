class Solution {
public:
    int longestString(int x, int y, int z) {
        if (x < y) {
            return 2*(2*x + 1 + z);   // BB AA BB
        }
        if (x == y) {
            return 2*(x + y + z);   // AA BB AA BB AB
        }
        return 2*max(2*y + 1, 2*y + 1 + z);   // y < x
    }
};