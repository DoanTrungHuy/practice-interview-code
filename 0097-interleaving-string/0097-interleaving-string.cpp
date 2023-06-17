int memo[101][101][201];

class Solution {
private:
    string s1, s2, s3;
    int size1, size2, size3;
    
public:
    int dp(int i, int j, int k) {
        if (i == size1 and j == size2 and k == size3) {
            return true;
        }
        if (memo[i][j][k] != -1) {
            return memo[i][j][k];
        }
        
        int ans = 0;
        
        if (i < size1 and s1[i] == s3[k]) {
            ans |= dp(i + 1, j, k + 1);
        }
        if (ans == 1) {
            return memo[i][j][k] = ans;
        }
        if (j < size2 and s2[j] == s3[k]) {
            ans |= dp(i, j + 1, k + 1);
        }
        return memo[i][j][k] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(memo, -1, sizeof(memo));
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        this->size1 = s1.size();
        this->size2 = s2.size();
        this->size3 = s3.size();
        return dp(0, 0, 0) == 1;
    }
};