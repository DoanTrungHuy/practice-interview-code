int memo[4005][4005];
using ll = long long;

class Solution {
private:
    string s;
    int n;
    vector<ll> h, p;
    
public:
    const ll MOD = 1e9 + 7, BASE = 47;
    
    const ll get_hash(ll left, ll right) {
        left++;
        right++;
        return (h[right] - (h[left - 1]*p[right - left + 1]) % MOD + MOD*MOD) % MOD;
    }
    
    int dp(int i, int len) {
        if (i >= n or len > n) {
            return 0;
        }
        if (memo[i][len] != -1) {
            return memo[i][len];
        }
        int ans = max(dp(i, len + 1), 1 + dp(n, n + 1));
        if (2*len + i - 1 < n and get_hash(i, len + i - 1) == get_hash(i + len, 2*len + i - 1)) {
            ans = max(ans, 1 + dp(i + len, 1));
        }
        return memo[i][len] = ans;
    }
    
    int deleteString(string s) {
        // Rolling Hash
        // Dynamic Programming: (i, LEN)
        // DP(i, LEN) -> MAX(DP(i, LEN + 1), DP(N, LEN))
        // IF (==) DP(i + LEN, 1)
        // LEN = j - i + 1
        // j = LEN + i - 1
        // IF hash(i, LEN + i - 1) == hash(i + LEN, 2*LEN + i - 1)
        // hash(1, 2) == hash(3, 4)
        memset(memo, -1, sizeof(memo));
        this->s = s;
        this->n = s.size();
        h.resize(n + 1, 0);
        p.resize(n + 1, 0);
        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            h[i + 1] = (h[i]*BASE + s[i] - 'a') % MOD;
            p[i + 1] = (p[i]*BASE) % MOD;
        }
        return dp(0, 1);
    }
};