class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // 2 4 6 8
        vector<int> flatten_grid;
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                flatten_grid.push_back(grid[i][j]);
            }
        }

        sort(flatten_grid.begin(), flatten_grid.end());

        int target = flatten_grid[n*m / 2];
        int r = flatten_grid[0] % x;

        for (int e : flatten_grid) {
            if (e % x != r) {
                return -1;
            }
        }

        // abs(v[i] - k*x) = target

        int ans = 0;

        for (int i = 0; i < n*m;  ++i) {
            ans += abs(flatten_grid[i] - target) / x;
        }

        return ans;
    }
};