const int MN = 1e4 + 10;
int memo[MN][7][7];
const int MOD = 1e9 + 7;

class Solution {
private:
    int n;
    
public:
    int dp(int i, int p1, int p2) {
        if (i == n) {
            return 1;
        }
        if (memo[i][p1][p2] != -1) {
            return memo[i][p1][p2];
        }
        int ans = 0;
        for (int j = 1; j <= 6; ++j) {
            if (i == 0) {
                ans = (ans + dp(i + 1, j, p1)) % MOD;
            }
            else {
                if (j == p1 || j == p2 || __gcd(p1, j) != 1) {
                    continue;
                }
                ans = (ans + dp(i + 1, j, p1)) % MOD;
            }
        }
        return memo[i][p1][p2] = ans;
    }
    
    int distinctSequences(int n) {
        this->n = n;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, 0);
    }
};