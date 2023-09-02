using ll = long long;
const int MN = 1e6 + 1;
ll p[MN];
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
            return (res * a) % MOD;
        }
        return res;
    }
    
    ll C(ll n, ll k) {
        ll res = p[n];
        res = (res * exp(p[n - k], MOD - 2)) % MOD;
        res = (res * exp(p[k], MOD - 2)) % MOD;
        return res;
    }
    
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<ll> cnt(26, 0);
        
        for (char c : s) {
            cnt[c - 'a']++;
        }
        
        if (cnt.size() < k) {
            return 0;
        }
        
        p[0] = 1LL;
        
        for (int i = 1; i < MN; ++i) {
            p[i] = (p[i - 1] * i) % MOD;
        }
        
        sort(cnt.begin(), cnt.end());
        
        long long ans = 1LL;
        
        for (int i = 25; i >= 0; --i) {
            if (k > 0) {
                (ans *= cnt[i]) %= MOD;
                k -= 1;
                if (k == 0) {
                    int total_equal = 0;
                    int p = -1; 
                    for (int j = 0; j <= 25; j++) {
                        if (cnt[j] == cnt[i]) {
                            total_equal++; 
                            p = j; 
                        }
                    }
                    (ans *= C(total_equal, p - i + 1)) %= MOD;
                }
            }
            else {
                break;
            }
        }
        
        return ans;
    }
};