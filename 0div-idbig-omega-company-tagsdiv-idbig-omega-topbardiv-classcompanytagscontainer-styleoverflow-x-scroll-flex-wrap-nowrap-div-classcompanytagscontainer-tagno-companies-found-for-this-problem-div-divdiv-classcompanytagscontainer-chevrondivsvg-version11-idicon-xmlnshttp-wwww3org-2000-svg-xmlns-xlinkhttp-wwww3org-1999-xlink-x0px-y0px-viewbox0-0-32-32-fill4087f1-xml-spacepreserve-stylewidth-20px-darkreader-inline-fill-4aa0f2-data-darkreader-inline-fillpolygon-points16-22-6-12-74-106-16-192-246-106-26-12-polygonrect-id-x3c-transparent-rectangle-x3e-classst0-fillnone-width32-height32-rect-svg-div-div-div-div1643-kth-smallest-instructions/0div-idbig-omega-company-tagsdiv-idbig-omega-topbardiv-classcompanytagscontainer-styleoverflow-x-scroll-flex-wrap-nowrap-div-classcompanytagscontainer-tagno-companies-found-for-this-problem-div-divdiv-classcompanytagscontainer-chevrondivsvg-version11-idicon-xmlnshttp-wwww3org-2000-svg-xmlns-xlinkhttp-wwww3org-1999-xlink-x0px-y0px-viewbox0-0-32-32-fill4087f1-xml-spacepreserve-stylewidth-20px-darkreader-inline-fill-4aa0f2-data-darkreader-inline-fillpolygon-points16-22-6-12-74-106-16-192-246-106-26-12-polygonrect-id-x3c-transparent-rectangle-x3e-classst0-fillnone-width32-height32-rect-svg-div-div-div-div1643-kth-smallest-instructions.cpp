class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        const int n = destination[0];
        const int m = destination[1];
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        string path = "";
        int r = 0, c = 0;
        
        while (r < n or c < m) {
            if (c < m and dp[r][c] >= k) {
                path.push_back('H');
                c++;
            }
            else {
                if ((k -= dp[r][c]) > 0) {
                    c--;
                    path.pop_back();
                }
                path.push_back('V');
                r++;
            }
        }
        
        return path;
    }
};