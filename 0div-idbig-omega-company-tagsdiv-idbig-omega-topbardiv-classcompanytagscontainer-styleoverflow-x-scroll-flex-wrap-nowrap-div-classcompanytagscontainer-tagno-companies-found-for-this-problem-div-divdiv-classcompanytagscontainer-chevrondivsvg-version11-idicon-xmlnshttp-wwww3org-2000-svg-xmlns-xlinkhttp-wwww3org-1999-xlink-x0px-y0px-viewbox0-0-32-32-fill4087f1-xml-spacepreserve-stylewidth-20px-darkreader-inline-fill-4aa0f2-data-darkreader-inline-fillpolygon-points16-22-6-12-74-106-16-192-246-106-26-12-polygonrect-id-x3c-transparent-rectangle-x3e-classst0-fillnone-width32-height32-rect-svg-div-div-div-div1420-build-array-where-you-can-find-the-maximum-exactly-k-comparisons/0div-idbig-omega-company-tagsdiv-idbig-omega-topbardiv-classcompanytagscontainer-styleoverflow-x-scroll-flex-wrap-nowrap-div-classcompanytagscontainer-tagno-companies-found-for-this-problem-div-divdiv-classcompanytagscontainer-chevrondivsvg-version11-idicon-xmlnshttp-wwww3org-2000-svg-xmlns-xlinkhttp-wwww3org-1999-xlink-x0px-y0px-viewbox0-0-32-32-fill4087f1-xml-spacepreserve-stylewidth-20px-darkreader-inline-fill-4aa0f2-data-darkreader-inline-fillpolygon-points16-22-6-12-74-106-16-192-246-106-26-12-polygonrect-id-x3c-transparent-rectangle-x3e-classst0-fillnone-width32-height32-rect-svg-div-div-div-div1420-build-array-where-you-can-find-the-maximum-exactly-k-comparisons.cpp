int memo[51][101][51];
const int MOD = 1e9 + 7;
class Solution {
private:
    int n, m, k;
    
public:
    int dp(int i, int p, int c) {
        if (c < 0) {
            return 0;
        }
        if (i == n) {
            return c == 0;
        }
        if (memo[i][p][c] != -1) {
            return memo[i][p][c];
        }
        int ans = 0;
        for (int j = 1; j <= m; ++j) {
            ans = (ans + dp(i + 1, max(j, p), c - (j > p))) % MOD;
        }
        return memo[i][p][c] = ans;
    }
    
    int numOfArrays(int n, int m, int k) {
        this->n = n;
        this->m = m;
        this->k = k;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, k);
    }
};