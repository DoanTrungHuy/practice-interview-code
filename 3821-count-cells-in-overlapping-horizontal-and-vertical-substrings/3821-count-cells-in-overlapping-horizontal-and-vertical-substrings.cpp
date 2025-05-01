class Solution {
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        const int n = grid.size();
        const int m = grid[0].size();

        vector<char> hor, ver;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hor.push_back(grid[i][j]);
            }
        }

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                ver.push_back(grid[i][j]);
            }
        }

        using ll = long long;
        const ll MOD = 1e9 + 7;
        const ll BASE = 31;
        ll hash_pattern = 0;
        ll power_k = 1;
        int k = pattern.size();
        
        for (int i = 0; i < k; ++i) {
            if (i < k - 1) {
                power_k = (power_k * BASE) % MOD;
            }
            hash_pattern = (hash_pattern * BASE + pattern[i] - 'a') % MOD;
        }

        vector<int> ver_mark(n*m + 1), hor_mark(n*m + 1);

        {
            ll curr_hash = 0;

            for (int i = 0, j = 0; i < hor.size(); ++i) {
                curr_hash = (curr_hash*BASE + hor[i] - 'a') % MOD;
                if (i - j + 1 == k) {
                    if (curr_hash == hash_pattern) {
                        hor_mark[j] += 1;
                        hor_mark[i + 1] -= 1;
                    }
                    curr_hash = ((curr_hash - ((hor[j] - 'a') * power_k) % MOD + MOD) % MOD);
                    j++;
                }
            }
        }

        {
            ll curr_hash = 0;

            for (int i = 0, j = 0; i < ver.size(); ++i) {
                curr_hash = (curr_hash*BASE + ver[i] - 'a') % MOD;
                if (i - j + 1 == k) {
                    if (curr_hash == hash_pattern) {
                        ver_mark[j] += 1;
                        ver_mark[i + 1] -= 1;
                    }
                    curr_hash = ((curr_hash - ((ver[j] - 'a') * power_k) % MOD + MOD) % MOD);
                    j++;
                }
            }
        }

        for (int i = 1; i < m*n; ++i) {
            hor_mark[i] += hor_mark[i - 1];
            ver_mark[i] += ver_mark[i - 1];
        }

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans += hor_mark[i*m + j] && ver_mark[j*n + i];
            }
        }

        return ans;
    }
};