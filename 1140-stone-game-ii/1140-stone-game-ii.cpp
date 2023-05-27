class Solution {
private:
    vector<int> piles;
    int n;

public:
    int memo[2][101][101];

    int dp(bool alice, int i, int M) {
        if (i == n) {
            return 0;
        }
        if (memo[alice][i][M] != -1) {
            return memo[alice][i][M];
        }
        int ans = alice ? 0 : INT_MAX;
        int total = 0;
        for (int X = 1; X <= 2 * M and X + i - 1 != n; ++X) {
            total += piles[i + X - 1];
            if (alice) {
                ans = max(ans, total + dp(!alice, i + X, max(X, M)));
            }
            else {
                ans = min(ans, dp(!alice, i + X, max(X, M)));
            }
        }
        return memo[alice][i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        this->piles = piles;
        this->n = piles.size();
        memset(memo, -1, sizeof(memo));
        return dp(true, 0, 1);
    }
};