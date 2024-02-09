const int MN = 1e4 + 10;
const int MM = 30;
const int MOD = 1e9 + 7;

class Solution {
private:
    int n, maxValue;
    
public:
    long long memo[MN + 1][MM + 1];
    long long cnt[MM + 1][MN + 1];
    vector<int> num_div[MN + 1];
    
    long long dp(int i, int j) {
        if (i == 0) {
           return j == 0; 
        }
        if (j == 0) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        return memo[i][j] = (dp(i - 1, j) + dp(i - 1, j - 1)) % MOD;
    }
    
    long long dfs(int i, int j) {
        if (i == 1) {
            return 1;
        }
        if (cnt[i][j] != -1) {
            return cnt[i][j];
        }
        long long ans = 0;
        for (int p : num_div[j]) {
            ans = (ans + dfs(i - 1, p)) % MOD;
        }
        return cnt[i][j] = ans;
    }
    
    int idealArrays(int n, int maxValue) {
        memset(memo, -1, sizeof(memo));
        memset(cnt, -1, sizeof(cnt));
        this->n = n;
        this->maxValue = maxValue;
        
        for (int i = 1; i <= maxValue; ++i) {
            for (int j = 2*i; j <= maxValue; j += i) {
                num_div[j].push_back(i);
            }
        }
        
        long long ans = 0;
        
        for (int i = 1; i <= MM; ++i) {
            for (int j = 1; j <= maxValue; ++j) {
                ans += (dfs(i, j) * dp(n, i)) % MOD;
            }
        }
        
        return (ans + MOD) % MOD;
    }
};