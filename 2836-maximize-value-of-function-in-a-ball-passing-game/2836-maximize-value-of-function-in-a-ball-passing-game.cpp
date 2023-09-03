using ll = long long;
using pr = pair<int, ll>;

class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        const int n = receiver.size();
        const int m = log2(k) + 1;
        
        pr dp[n][m];
        
        for (int i = 0; i < n; ++i) {
            dp[i][0] = {receiver[i], receiver[i]};
        }
        
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                int np = dp[i][j - 1].first;
                dp[i][j] = {dp[np][j - 1].first, dp[i][j - 1].second + dp[np][j - 1].second};
            }
        }
        
        const auto jump = [&](int node, ll k) -> ll {
            ll sum = 0;
            for (ll j = m; j >= 0; --j) {
                if (k & (1LL << j)) {
                    sum += dp[node][j].second;
                    node = dp[node][j].first;
                }
            }
            return sum;
        };
        
        ll ans = 0LL;
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, jump(i, k) + i);
        }
        
        return ans;
    }
};