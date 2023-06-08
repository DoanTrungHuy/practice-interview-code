class Solution {
private:
    int min_sum, max_sum;
    
public:
    int memo[23][2][401];
    const int MOD = 1e9 + 7;
    
    int dp(int i, bool tight, int sum, const string &s) {
        if (i == (int)s.size()) {
            return min_sum <= sum and sum <= max_sum;
        }
        if (memo[i][tight][sum] != -1) {
            return memo[i][tight][sum];
        }
        int limit = tight ? s[i] - '0' : 9;
        int ans = 0;
        for (int d = 0; d <= limit; ++d) {
            ans = (ans + dp(i + 1, tight and d == limit, sum + d, s)) % MOD;
        }
        return memo[i][tight][sum] = ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        this->min_sum = min_sum;
        this->max_sum = max_sum;
        memset(memo, -1, sizeof(memo));
        int upper = dp(0, true, 0, num2);
        memset(memo, -1, sizeof(memo));
        int lower = dp(0, true, 0, num1);
        int sumLower = 0;
        for (char c : num1) {
            sumLower += c - '0';
        }
        if (min_sum <= sumLower and sumLower <= max_sum) {
            lower--;
        }
        return (upper - lower + MOD) % MOD;
    }
};