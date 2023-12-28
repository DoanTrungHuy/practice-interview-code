int memo[101][101][101][27];

class Solution {
private:
    string s;
    
public:
    int dp(int i, int c, int k, int p) {
        if (k < 0) {
            return 1e9;
        }
        if (i == (int)s.size()) {
            return 0;
        }
        if (memo[i][c][k][p] != -1) {
            return memo[i][c][k][p];
        }
        int ans = dp(i + 1, c, k - 1, p);
        if ((s[i] - 'a') == p) {
            int ins = (c == 1 or c == 9 or c == 99);
            return memo[i][c][k][p] = min(ans, ins + dp(i + 1, c + 1, k, p));
        }
        return memo[i][c][k][p] = min(ans, 1 + dp(i + 1, 1, k, s[i] - 'a'));
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(memo, -1, sizeof(memo));
        this->s = s;
        return dp(0, 0, k, 26);
    }
};