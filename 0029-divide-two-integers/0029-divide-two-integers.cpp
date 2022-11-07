class Solution {
public:
    int divide(int dividend, int divisor) {
        if ((dividend == INT_MAX || dividend == INT_MIN) and abs(divisor) == 1) {
            if ((dividend < 0 and divisor < 0) or (dividend > 0 and divisor > 0)) {
                return INT_MAX;
            }
            else {
                return INT_MIN;
            }
        }
        return dividend / divisor;
    }
};