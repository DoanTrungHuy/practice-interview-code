class Solution {
private:
    string s, p;
    int n, m;
    
public:
    vector<vector<int>> memo;
    
    int dp(int i, int j) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        if (j == m) {
            return memo[i][j] = i == n;
        }
        
        if (i == n) {
            return memo[i][j] = p[j] == '*' and dp(i, j + 1);
        }
        
        if (p[j] == '?' or s[i] == p[j]) {
            return memo[i][j] = dp(i + 1, j + 1);
        }
        
        if (p[j] == '*') {
            return memo[i][j] = dp(i + 1, j) or dp(i, j + 1);
        }
        
        return memo[i][j] = 0;
    }
    
    bool isMatch(string s, string p) {
        n = s.size(), m = p.size();
        memo.resize(n + 1, vector<int>(m + 1, -1));
        this->s = s;
        this->p = p;
        return dp(0, 0);
    }
};