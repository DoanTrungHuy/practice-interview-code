using ll = long long;
const ll mod = 1e9 + 13;
const ll base = 26;

class Solution {
public:
    long long sumScores(string s) {
        const int n = (int)s.size();
        vector<ll> h(n + 1), p(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            h[i] = (h[i - 1]*base + s[i - 1] - 'a' + 1) % mod;
            p[i] = (p[i - 1]*base) % mod;
        }
        const auto getHash = [&](int l, int r) {
            return (h[r] - h[l - 1]*p[r - l + 1] + mod*mod) % mod;
        };
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            int l = 1;
            int r = n - i + 1;
            int val = 0;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (getHash(1, m) == getHash(i, i + m - 1)) {
                    val = m;
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            ans += 1LL*val;
        }
        return ans;
    }
};