class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        n--;
        
        // 000
        // 001
        // 010
        
        // x: 100101
        // n: 0101
        
        int j = 0;
        
        while (x) {
            if ((x & 1) == 0) {
                ans |= (1LL << j)*(n&1);
                n >>= 1;
            }
            x >>= 1;
            j++;
        }
        
        while (n) {
            ans |= (1LL << j)*(n&1);
            n >>= 1;
            j++;
        }
        
        return ans;
    }
};