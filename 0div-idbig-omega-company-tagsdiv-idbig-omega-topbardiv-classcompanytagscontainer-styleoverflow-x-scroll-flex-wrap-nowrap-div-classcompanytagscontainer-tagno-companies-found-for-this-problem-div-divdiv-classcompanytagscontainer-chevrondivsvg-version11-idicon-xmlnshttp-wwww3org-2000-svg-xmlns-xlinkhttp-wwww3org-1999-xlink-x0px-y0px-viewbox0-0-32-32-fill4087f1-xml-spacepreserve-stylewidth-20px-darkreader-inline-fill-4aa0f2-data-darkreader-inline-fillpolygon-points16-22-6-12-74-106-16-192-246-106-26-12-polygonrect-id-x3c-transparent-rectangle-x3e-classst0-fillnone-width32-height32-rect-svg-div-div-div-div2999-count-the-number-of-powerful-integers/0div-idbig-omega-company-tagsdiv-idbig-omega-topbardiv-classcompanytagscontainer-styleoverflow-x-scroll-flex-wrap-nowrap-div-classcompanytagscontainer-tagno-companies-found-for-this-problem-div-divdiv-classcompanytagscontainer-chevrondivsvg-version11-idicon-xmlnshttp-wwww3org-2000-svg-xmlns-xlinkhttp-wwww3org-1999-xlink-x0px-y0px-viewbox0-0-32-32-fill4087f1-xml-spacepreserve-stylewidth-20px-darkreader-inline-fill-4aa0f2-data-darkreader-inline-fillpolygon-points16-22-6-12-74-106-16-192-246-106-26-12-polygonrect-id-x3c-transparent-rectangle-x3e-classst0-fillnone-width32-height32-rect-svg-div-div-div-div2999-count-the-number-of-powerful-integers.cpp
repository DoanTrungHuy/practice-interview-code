using ll = long long;
ll memo[17][2];

class Solution {
private:
    string s;
    int limit;
    
public:
    ll dp(string &nums, int i, bool tight) {
        int n = nums.size();
        int m = s.size();
        
        if (i == n) {
            return 1;
        }
        
        if (n < m) {
            return 0;
        }
        
        if (memo[i][tight] != -1) {
            return memo[i][tight];
        }
        
        int curr_limit = tight ? nums[i] - '0' : 9;
        int r_limit = min(curr_limit, limit);
        ll ans = 0;
        
        for (int d = 0; d <= r_limit; ++d) {
            if (i >= n - m) {
                if (d == s[i - (n - m)] - '0') {
                    ans += dp(nums, i + 1, tight and d == curr_limit);
                    break;
                }
            }
            else {
                ans += dp(nums, i + 1, tight and d == curr_limit);
            }
        }
        
        return memo[i][tight] = ans;
    }
    
    ll numberOfPowerfulInt(ll start, ll finish, int limit, string s) {
        this->s = s;
        this->limit = limit;
        memset(memo, -1, sizeof(memo));
        string num1 = to_string(finish);
        string num2 = to_string(start - 1);
        ll ans = dp(num1, 0, true);
        memset(memo, -1, sizeof(memo));
        return ans - dp(num2, 0, true);
    }
};