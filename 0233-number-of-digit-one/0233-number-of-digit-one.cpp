class Solution {
private:
    string num;
    int m;
    
public:
    int memo[12][2][12];
    
    int dp(int i, bool tight, int cnt) {
        if (i == m) {
            return cnt;
        }
        if (memo[i][tight][cnt] != -1) {
            return memo[i][tight][cnt];
        }
        int limit = tight ? (num[i] - '0') : 9;
        int ans = 0;
        for (int d = 0; d <= limit; ++d) {
            bool newTight = tight and d == limit;
            int newCnt = cnt + (d == 1);
            ans += dp(i + 1, newTight, newCnt);
        }
        return memo[i][tight][cnt] = ans;
    }
    
    int countDigitOne(int n) {
        num = to_string(n);
        m = num.size();
        memset(memo, -1, sizeof(memo));
        return dp(0, true, 0);
    }
};