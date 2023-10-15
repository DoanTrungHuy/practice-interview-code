class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        const int MOD = 12345;
        using ll = long long;
        vector<ll> pref(n*m, 1), suff(n*m, 1);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i*m + j - 1 >= 0) {
                    (pref[i*m + j] *= pref[i*m + j - 1]) %= MOD;
                }
                (pref[i*m + j] *= grid[i][j]) %= MOD;
            }
        }
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i*m + j + 1 < m*n) {
                    (suff[i*m + j] *= suff[i*m + j + 1]) %= MOD;
                }
                (suff[i*m + j] *= grid[i][j]) %= MOD;
            }
        }
        
        vector<vector<int>> ans(n, vector<int>(m, 1));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i*m + j + 1 < m*n) {
                    ans[i][j] = (ans[i][j] * suff[i*m + j + 1]) % MOD;
                }
                if (i*m + j - 1 >= 0) {
                    ans[i][j] = (ans[i][j] * pref[i*m + j - 1]) % MOD;
                }
            }
        }
        
        return ans;
    }
};
