class Solution {
public:
    bool checkPartitioning(string s) {
        const int n = s.size();
        using ll = long long;
        vector<ll> h[2], p(n + 1);
        h[0].resize(n + 1);
        h[1].resize(n + 1);
        p[0] = 1;
        const ll BASE = 3, MOD = 1e9 + 7;
        
        string t = s;
        reverse(t.begin(), t.end());
        
        for (int i = 0; i < n; ++i) {
            h[0][i + 1] = (h[0][i]*BASE + s[i] - 'a') % MOD;
            h[1][i + 1] = (h[1][i]*BASE + t[i] - 'a') % MOD;
            p[i + 1] = (p[i]*BASE) % MOD;
        }
        
        const auto sliced_string = [&](int l, int r, int t) -> ll {
            return (h[t][r] - h[t][l - 1]*p[r - l + 1] + MOD*MOD) % MOD;
        };
        
        const auto check_palindrome = [&](int l, int r) -> bool {
            return sliced_string(l, r, 0) == sliced_string(n - r + 1, n - l + 1, 1);
        };
        
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n - 1; ++j) {
                bool check[3] = {};
                check[0] = check_palindrome(1, i);
                check[1] = check_palindrome(i + 1, j);
                check[2] = check_palindrome(j + 1, n);
                if (check[0] and check[1] and check[2]) {
                    return true;
                }
            }
        }
        
        return false;
    }
};