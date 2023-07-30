class Solution {
public:
    int memo[101][2][2][12];
    int MOD = 1e9 + 7;
    
    int dp(string &s, int i, bool tight, bool headZero, int prev) {
        if (i == s.size()) {
            return 1;
        }
        
        if (memo[i][tight][headZero][prev] != -1) {
            return memo[i][tight][headZero][prev];
        }
        
        int limit = tight ? s[i] - '0' : 9;
        
        int ans = 0;
        
        for (int d = 0; d <= limit; ++d) {
            if (abs(d - prev) != 1 and !headZero) {
                continue;
            }
            ans = (ans + dp(s, i + 1, tight and d == limit, d == 0 and headZero, d)) % MOD;
        }
        
        return memo[i][tight][headZero][prev] = ans;
    }
    
    int countSteppingNumbers(string low, string high) {
        memset(memo, -1, sizeof(memo));
        int right = dp(high, 0, true, true, 11);
        memset(memo, -1, sizeof(memo));
        int left = dp(low, 0, true, true, 11);
        
        bool remain = true;
        char prev = low[0];
        
        for (int i = 1; i < low.size(); ++i) {
            if (abs(low[i] - prev) != 1) {
                remain = false;
                break;
            }
            prev = low[i];
        }
       
        return (right - left + remain + MOD) % MOD;
    }
};