#define ODD 0
#define EVEN 1

class Solution {
private:
    vector<vector<vector<long long>>> memo;
    int m, n;
    vector<vector<int>> waitCost;

public:
    long long dp(int i, int j, int state) {
        if (i == m - 1 && j == n - 1) {
            return (i + 1)*(j + 1);
        }
        if (memo[i][j][state] != -1) {
            return memo[i][j][state];
        }
        if (state == EVEN) {
            long long ans = 1e12;
            if (i + 1 < m) {
                ans = min(ans, dp(i + 1, j, ODD) + (i + 1)*(j + 1));
            }
            if (j + 1 < n) {
                ans = min(ans, dp(i, j + 1, ODD) + (i + 1)*(j + 1));
            }
            return memo[i][j][state] = ans;
        }
        long long ans = dp(i, j, EVEN) + waitCost[i][j];
        return memo[i][j][state] = ans;
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        memo.resize(m, vector<vector<long long>>(n, vector<long long>(2, -1)));
        this->m = m;
        this->n = n;
        this->waitCost = waitCost;
        return dp(0, 0, EVEN);
    }
};