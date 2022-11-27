class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        for (int i = 1; i <= n; ++i) {
            if ((total + i) % 2 == 1) {
                continue;
            }
            int s = i * (i + 1) / 2;
            if (s == (total + i) / 2) {
                return i;
            }
        }
        return -1;
    }
};