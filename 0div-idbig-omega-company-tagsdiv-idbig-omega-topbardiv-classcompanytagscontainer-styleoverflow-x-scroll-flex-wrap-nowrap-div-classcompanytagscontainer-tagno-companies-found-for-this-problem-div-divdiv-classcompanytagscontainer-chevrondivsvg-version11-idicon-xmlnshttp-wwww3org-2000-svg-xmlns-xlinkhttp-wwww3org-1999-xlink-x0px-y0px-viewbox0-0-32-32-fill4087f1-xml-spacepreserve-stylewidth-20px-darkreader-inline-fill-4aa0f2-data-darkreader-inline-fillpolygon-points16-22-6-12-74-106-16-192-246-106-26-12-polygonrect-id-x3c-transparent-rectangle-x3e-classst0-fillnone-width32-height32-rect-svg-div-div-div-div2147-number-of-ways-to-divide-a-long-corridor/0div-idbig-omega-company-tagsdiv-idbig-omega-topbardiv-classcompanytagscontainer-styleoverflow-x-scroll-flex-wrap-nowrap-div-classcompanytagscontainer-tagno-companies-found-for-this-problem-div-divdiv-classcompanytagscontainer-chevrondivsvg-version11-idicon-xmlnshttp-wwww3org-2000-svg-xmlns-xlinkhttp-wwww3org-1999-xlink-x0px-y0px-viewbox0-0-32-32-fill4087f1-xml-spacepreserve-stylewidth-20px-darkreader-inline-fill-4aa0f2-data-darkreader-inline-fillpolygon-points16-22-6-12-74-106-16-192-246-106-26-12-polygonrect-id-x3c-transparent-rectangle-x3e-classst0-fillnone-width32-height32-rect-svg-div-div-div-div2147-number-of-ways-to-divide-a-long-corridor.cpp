int memo[100005][3];
const int MOD = 1e9 + 7;

class Solution {
private:
    string corridor;
    
public:
    int dp(int i, int j) {
        if (j > 2) {
            return 0;
        }
        if (i == (int)corridor.size()) {
            return j == 2;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int &ans = memo[i][j];
        if (corridor[i] == 'S') {
            ans = dp(i + 1, j + 1);
            if (j == 2) {
                (ans += dp(i + 1, 1)) %= MOD;
            }
        }
        else {
            ans = dp(i + 1, j);
            if (j == 2) {
                (ans += dp(i + 1, 0)) %= MOD;
            }
        }
        return ans;
    }
    
    int numberOfWays(string corridor) {
        this->corridor = corridor;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0);
    }
};