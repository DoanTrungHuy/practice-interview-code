int memo[101][101][101];

class Solution {
private:
    string s;
    int n;
    
public:
    int count_palind(int left, int right) {
        int cnt = 0;
        while (left < right) {
            cnt += s[left] != s[right];
            left++;
            right--;
        }
        return cnt;
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
        return dp(0, 0, k);
    }
};