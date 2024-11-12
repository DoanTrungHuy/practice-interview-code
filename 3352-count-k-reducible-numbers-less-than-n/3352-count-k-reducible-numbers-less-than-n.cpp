const int MOD = 1e9 + 7;
int ok[888][6];
int memo[888][2][888];

class Solution {
private:
    string s;
    int n;
    int amount;
    
public:
    int dfs(int cnt, int k) {
        if (cnt == 1) {
            return k >= 0;
        }
        if (k < 0 || cnt == 0) {
            return false;
        }
        if (ok[cnt][k] != -1) {
            return ok[cnt][k];
        }
        int new_cnt = 0;
        while (cnt) {
            new_cnt += cnt&1;
            cnt >>= 1;
        }
        return ok[cnt][k] = dfs(new_cnt, k - 1);
    }
    
    int dp(int i, int tight, int cnt) {
        if (i == n) {
            return dfs(cnt, amount - 1);
        }
        if (memo[i][tight][cnt] != -1) {
            return memo[i][tight][cnt];
        }
        int limit = tight ? s[i] - '0' : 1;
        int ans = 0;
        for (int d = 0; d <= limit; ++d) {
            ans = (ans + dp(i + 1, tight and d == limit, cnt + d)) % MOD;
        }
        return memo[i][tight][cnt] = ans;
    }
    
    int countKReducibleNumbers(string s, int k) {
        this->amount = k;
        memset(ok, -1, sizeof ok);
        memset(memo, -1, sizeof memo);
        this->s = s;
        this->n = s.size();
        
        int cnt_bit1 = 0;
        
        for (char c : s) {
            cnt_bit1 += c == '1';
        }
        
        return (dp(0, 1, 0) - dfs(cnt_bit1, amount - 1) + MOD) % MOD;
    }
};