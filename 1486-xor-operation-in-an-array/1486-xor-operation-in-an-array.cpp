class Solution {
public:
    int xorOperation(int n, int start) {
        int i = 0;
        int p = start + 2 * i;
        i++;
        n--;
        while (n--) {
            p ^= (start + 2 * i);
            i++;
        }
        return p;
    }
};