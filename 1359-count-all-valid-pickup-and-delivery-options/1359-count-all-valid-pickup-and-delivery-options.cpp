class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        const int MOD = 1e9 + 7;
        
        for (int i = 1; i <= 2*n; ++i) {
            ans = ans*i;
            if (i % 2 == 0) {
                ans /= 2;
            }
            ans %= MOD;
        }
        
        return (int)ans;
    }
};