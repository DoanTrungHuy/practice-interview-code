vector<vector<int>> dir = {{4,6}, {6,8}, {7,9}, {4,8}, {3,9,0}, {}, {1,7,0}, {2,6}, {1,3}, {2,4}};
const int MOD = 1e9 + 7;
int memo[10][5001];

class Solution {
public:
    int dp(int i, int len) {
        if (len == 0) {
            return 1;
        }
        if (memo[i][len] != -1) {
            return memo[i][len];
        }
        int ans = 0;
        for (int j : dir[i]) {
            ans = (ans + dp(j, len - 1)) % MOD;
        }
        return memo[i][len] = ans;
    }
    
    int knightDialer(int n) {
        int ans = 0;
        for (int i = 0; i < 10; ++i) {
            memset(memo, -1, sizeof(memo));
            ans = (ans + dp(i, n - 1)) % MOD;
        }
        return ans;
    }
};