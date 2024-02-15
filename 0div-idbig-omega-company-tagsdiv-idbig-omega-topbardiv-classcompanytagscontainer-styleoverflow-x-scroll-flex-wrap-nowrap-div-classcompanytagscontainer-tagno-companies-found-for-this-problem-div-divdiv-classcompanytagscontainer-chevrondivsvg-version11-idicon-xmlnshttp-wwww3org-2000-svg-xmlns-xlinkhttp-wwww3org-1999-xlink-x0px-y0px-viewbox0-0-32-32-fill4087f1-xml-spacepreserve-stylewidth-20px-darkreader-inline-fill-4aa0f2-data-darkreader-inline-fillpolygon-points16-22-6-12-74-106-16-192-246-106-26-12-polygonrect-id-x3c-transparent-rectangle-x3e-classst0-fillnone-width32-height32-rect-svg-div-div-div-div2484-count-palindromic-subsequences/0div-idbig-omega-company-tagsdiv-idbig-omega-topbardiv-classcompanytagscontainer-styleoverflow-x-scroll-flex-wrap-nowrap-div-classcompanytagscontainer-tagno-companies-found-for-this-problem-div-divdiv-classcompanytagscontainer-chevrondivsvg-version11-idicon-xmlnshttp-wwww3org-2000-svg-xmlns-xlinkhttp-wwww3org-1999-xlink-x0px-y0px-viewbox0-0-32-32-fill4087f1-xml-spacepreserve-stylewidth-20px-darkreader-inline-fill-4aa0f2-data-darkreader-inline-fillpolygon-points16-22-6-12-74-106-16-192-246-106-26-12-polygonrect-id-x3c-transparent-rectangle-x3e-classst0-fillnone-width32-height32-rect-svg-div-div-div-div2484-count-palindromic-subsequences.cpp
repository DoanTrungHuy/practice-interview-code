using ll = long long;
const ll MOD = 1e9 + 7;
ll memo[10000][10][10][5];
const int M = 5;

class Solution {
private:
    string s;
    
public:
    ll dp(int i, int first, int second, int len) {
        if (len == M) {
            return 1;
        }
        if (i == s.size()) {
            return 0;
        }
        if (memo[i][first][second][len] != -1LL) {
            return memo[i][first][second][len];
        }
        ll ans = dp(i + 1, first, second, len);
        if (len == 0) {
            (ans += dp(i + 1, s[i] - '0', second, len + 1)) %= MOD;
        }
        else if (len == 1) {
            (ans += dp(i + 1, first, s[i] - '0', len + 1)) %= MOD;
        }
        else if (len == 2) {
            (ans += dp(i + 1, first, second, len + 1)) %= MOD;
        }
        else if (len == 3) {
            if (second == (s[i] - '0')) {
                (ans += dp(i + 1, first, second, len + 1)) %= MOD;
            }
        }
        else if (len == 4) {
            if (first == (s[i] - '0')) {
                (ans += dp(i + 1, first, second, len + 1)) %= MOD;
            }
        }
        return memo[i][first][second][len] = ans;
    }
    
    int countPalindromes(string s) {
        this->s = s;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, 0, 0);
    }
};