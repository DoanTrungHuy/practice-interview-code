
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const int n = img.size(), m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<vector<int>> DIR;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                DIR.push_back({i, j});
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int cnt = 0;
                for (vector<int> d : DIR) {
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if (!(0 <= ni and ni < n and 0 <= nj and nj < m)) {
                        continue;
                    }
                    cnt++;
                    ans[i][j] += img[ni][nj];
                }
                ans[i][j] /= cnt;
            }
        }

        return ans;
    }
};