class Solution {
private:
    int n, m;
    vector<string> strs;
    
public:
    int memo[101][102];
    
    int dp(int j, int p) {
        if (j == m) {
            return 0;
        }
        if (memo[j][p + 1] != -1) {
            return memo[j][p + 1];
        }
        int ans = dp(j + 1, p);
        if (p == -1) {
            ans = max(ans, dp(j + 1, j) + 1);
        }
        else {
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (strs[i][p] > strs[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = max(ans, dp(j + 1, j) + 1);
            }
        }
        return memo[j][p + 1] = ans;
    }
    
    int minDeletionSize(vector<string>& strs) {
        this->strs = strs;
        n = strs.size(), m = strs[0].size();
        memset(memo, -1, sizeof(memo));
        
        // dp(j, p) j sẽ là vị trí hiện tại, vị trí trước thằng p trước, p thì có thể là 
        // không liên tiếp
        // max(dp(j + 1, p), if all(for i range(n) str[i][p] <= str[i][j]) -> dp(j + 1, j) + 1)
        
        return m - dp(0, -1);
    }
};