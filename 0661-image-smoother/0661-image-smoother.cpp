class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cnt = 1, total = img[i][j];
                if (i - 1 >= 0) {
                    total += img[i - 1][j];
                    cnt += 1;
                }
                if (i + 1 < n) {
                    total += img[i + 1][j];
                    cnt += 1;
                }
                if (j - 1 >= 0) {
                    total += img[i][j - 1];
                    cnt += 1;
                }
                if (j + 1 < m) {
                    total += img[i][j + 1];
                    cnt += 1;
                }
                if (i - 1 >= 0 and j - 1 >= 0) {
                    total += img[i - 1][j - 1];
                    cnt += 1;
                }
                if (i - 1 >= 0 and j + 1 < m) {
                    total += img[i - 1][j + 1];
                    cnt += 1;
                } 
                if (i + 1 < n and j - 1 >= 0) {
                    total += img[i + 1][j - 1];
                    cnt += 1;
                }
                if (i + 1 < n and j + 1 < m) {
                    total += img[i + 1][j + 1];
                    cnt += 1;
                } 
                dp[i][j] = total / cnt;
            }
        }
        return dp;
    }
};