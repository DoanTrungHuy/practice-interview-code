using ll = long long;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;

        auto mul = [&](const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
            vector<vector<ll>> c(26, vector<ll>(26, 0));
            for (int i = 0; i < 26; ++i) {
                for (int k = 0; k < 26; ++k) {
                    for (int j = 0; j < 26; ++j) {
                        c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
                    }
                }
            }
            return c;
        };

        auto exp = [&](vector<vector<ll>> &mat, ll p) {
            vector<vector<ll>> c(26, vector<ll>(26, 0));
            for (int i = 0; i < 26; ++i) {
                c[i][i] = 1;
            }
            vector<vector<ll>> base = mat;
            while (p > 0) {
                if (p & 1) {
                    c = mul(c, base);
                }
                base = mul(base, base);
                p /= 2;
            }
            return c;
        };

        vector<vector<ll>> M(26, vector<ll>(26, 0));

        for (int c = 0; c < 26; ++c) {
            if (c == 25) {
                M[c][0] = 1;
                M[c][1] = 1;
            } 
            else {
                M[c][c + 1] = 1;
            }
        }

        vector<vector<ll>> r = exp(M, t);
        
        vector<ll> cnt(26, 0);
        
        for (char c : s) {
            cnt[c - 'a']++;
        }

        vector<ll> f(26, 0);

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                f[j] = (f[j] + cnt[i] * r[i][j]) % MOD;
            }
        }

        ll ans = 0;
        
        for (ll val : f) {
            ans = (ans + val) % MOD;
        }

        return ans;
    }
};