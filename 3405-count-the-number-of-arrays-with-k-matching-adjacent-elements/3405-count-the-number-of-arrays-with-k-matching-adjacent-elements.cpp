using ll = long long;
const ll MOD = 1e9 + 7;

class Solution {
public:
    ll exp(ll a, ll b) {
        if (b == 0) {
            return 1;
        }
        ll res = exp(a, b / 2);
        res = (res * res) % MOD;
        if (b & 1) {
            res = (res * a) % MOD;
        }
        return res;
    }

    int countGoodArrays(int n, int m, int k) {
        if (k >= n) {
            return 0;
        }

        vector<ll> f(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            f[i] = (f[i - 1] * i) % MOD;
        }

        ll r = n - k;
        if (r > n) {
            return 0;
        }

        ll nCr = (f[n - 1] * exp(f[r - 1], MOD - 2) % MOD * exp(f[n - r], MOD - 2) % MOD) % MOD;

        ll ans = (nCr * m % MOD * exp(m - 1, r - 1)) % MOD;

        return ans;
    }
};
