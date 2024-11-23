class Solution {
public:
    const int INF = INT_MIN;
    int memo1[1001][1001];
    int memo2[1001][1001];
    vector<vector<int>> a;
    int n;

    int dp1(int i, int j) {
        if (i == n) {
            return j == n ? 0 : INF;
        }
        if (j < 0 || j >= n) {
            return INF;
        }
        if (memo1[i][j] != -1) {
            return memo1[i][j];
        }
        return memo1[i][j] = a[i][j] + max({dp1(i + 1, j + 1), dp1(i + 1, j), dp1(i + 1, j - 1)});
    }

    int dp2(int i, int j) {
        if (i == n) {
            return j == n ? 0 : INF;
        }
        if (i < 0 || j >= n) {
            return INF;
        }
        if (memo2[i][j] != -1) {
            return memo2[i][j];
        }
        return memo2[i][j] = a[i][j] + max({dp2(i - 1, j + 1), dp2(i, j + 1), dp2(i + 1, j + 1)});
    }

    int maxCollectedFruits(vector<vector<int>>& a) {
        n = a.size();
        this->a = a;

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            ans += a[i][i];
            this->a[i][i] = 0;
        }

        memset(memo1, -1, sizeof memo1);
        ans += dp1(0, n - 1);

        memset(memo2, -1, sizeof memo2);
        ans += dp2(n - 1, 0);

        return ans;
    }
};
