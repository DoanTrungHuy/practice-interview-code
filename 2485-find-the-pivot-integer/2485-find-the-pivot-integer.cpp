class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        for (int i = 1; i <= n; ++i) {
            total += i;
            if (total % 2 == 1) {
                total -= i;
                continue;
            }
            int s = i * (i + 1) / 2;
            if (s == total / 2) {
                return i;
            }
            total -= i;
        }
        return -1;
    }
};