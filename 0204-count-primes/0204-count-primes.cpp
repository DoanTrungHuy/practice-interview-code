class Solution {
public:
    int countPrimes(int n) {
        vector<bool> dp(n + 1, false);
        
        for (int i = 2; i < n; ++i) {
            dp[i] = true;
        }
        
        for (int i = 2; i < n; ++i) {
            if (!dp[i]) {
                continue;
            } 
            for (int j = 2*i; j < n; j += i) {
                dp[j] = false;
            }
        }
        
        int cnt = 0;
        
        for (int i = 2; i < n; ++i) {
            cnt += dp[i];
        }
        
        return cnt;
    }
};