const int MOD = 1e9 + 7;
int memo[5001][4][4][4];
vector<int> colors = {1, 2, 3};

class Solution {
public:
    int dp(int n, int a0, int b0, int c0) {
        if (n == 0) {
            return 1;
        }
        if (memo[n][a0][b0][c0] != -1) {
            return memo[n][a0][b0][c0];
        }
        int ans = 0;
        for (int a : colors) {
            if (a == a0) {
                continue;
            }
            for (int b : colors) {
                if (b == b0 or b == a) {
                    continue;
                }
                for (int c : colors) {
                    if (c == c0 or b == c) {
                        continue;
                    }
                    ans = (ans + dp(n - 1, a, b, c)) % MOD;
                }
            }
        }
        return memo[n][a0][b0][c0] = ans;
    }
    
    int numOfWays(int n) {
        memset(memo, -1, sizeof(memo));
        return dp(n, 0, 0, 0);
    }
};