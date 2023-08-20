int memo[11][2][2][11][11][20];

class Solution {
private:
    int k;
    
public:
    int dp(string &s, int i, bool isZero, bool tight, int c1, int c2, int total = 0) {
        if (i == s.size()) {
            return c1 == c2 and !total;
        }    
        if (memo[i][isZero][tight][c1][c2][total] != -1) {
            return memo[i][isZero][tight][c1][c2][total];
        }
        int limit = tight ? s[i] - '0' : 9;
        int ans = 0;
        for (int d = 0; d <= limit; ++d) {
            if (isZero and d == 0) {
                ans += dp(s, i + 1, isZero and d == 0, tight and d == limit, c1, c2, total % k);
            }
            else if (d % 2 == 0) {
                ans += dp(s, i + 1, isZero and d == 0, tight and d == limit, c1 + 1, c2, (total*10 + d) % k);
            }
            else {
                ans += dp(s, i + 1, isZero and d == 0, tight and d == limit, c1, c2 + 1, (total*10 + d) % k);
            }
        }
        return memo[i][isZero][tight][c1][c2][total] = ans;
    }
    
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string s1 = to_string(low - 1);
        string s2 = to_string(high);
        this->k = k;
        memset(memo, -1, sizeof(memo));
        int cnt_high = dp(s2, 0, true, true, 0, 0);
        memset(memo, -1, sizeof(memo));
        int cnt_low = dp(s1, 0, true, true, 0, 0);
        return cnt_high - cnt_low;
    }
};