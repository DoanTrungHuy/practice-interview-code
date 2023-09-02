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
        unordered_map<int, ll> f;
        
        for (const char c : s) {
            f[c - 'a']++;
        }
        
        if (f.size() < k) {
            return 0LL;
        }
        
        p[0] = 1LL;
        for (int i = 1; i < MN; ++i) {
            p[i] = (p[i - 1] * i) % MOD;
        }
        
        priority_queue<int> pq;
        
        for (const auto &[_, cnt] : f) {
            pq.push(cnt);
        }
        
        ll ans = 1LL;
        
        while (k > 0) {
            ll occ = pq.top(), cnt = 0;
            while (!pq.empty() and occ == pq.top()) {
                cnt++;
                pq.pop();
            }
            if (k >= cnt) {
                (ans *= exp(occ, cnt)) %= MOD;
            }
            else {
                (ans *= (exp(occ, k) * C(cnt, k)) % MOD) %= MOD;
            }
            k -= cnt;
        }
        
        return (int) ans;
    }
};