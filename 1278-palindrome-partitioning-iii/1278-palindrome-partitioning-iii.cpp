int memo[101][101][101];
int sav[101][101];

class Solution {
private:
    string s;
    int n;
    
public:
    int count_palind(int left, int right) {
        if (left > right) {
            return 0;
        }
        if (sav[left][right] != -1) {
            return sav[left][right];
        }
        return sav[left][right] = (s[left] != s[right]) + count_palind(left + 1, right - 1);
    }
    
    int dp(int i, int p, int k) {
         if (i == n) {
            return 1e9;
        }
        if (k == 1) {
            return count_palind(p, n - 1);
        }
        if (memo[i][p][k] != -1) {
            return memo[i][p][k];
        }
        return memo[i][p][k] = min(
            {dp(i + 1, p, k), dp(i + 1, i + 1, k - 1) + count_palind(p, i)}
        );
    }
    
    int palindromePartition(string s, int k) {
        this->s = s;
        this->n = s.size();
        memset(memo, -1, sizeof(memo));
        memset(sav, -1, sizeof(sav));
        return dp(0, 0, k);
    }
};