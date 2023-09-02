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
        unordered_map<char, ll> cnt_characters;
        
        for (char c : s) {
            cnt_characters[c]++;
        }
        
        if (cnt_characters.size() < k) {
            return 0;
        }
        
        map<int, ll> cnt_freqs;
        
        for (const auto [_, c] : cnt_characters) {
            cnt_freqs[c]++;
        }
        
        p[0] = 1;
        for (int i = 1; i < MN; ++i) {
            p[i] = (p[i - 1] * i) % MOD;
        }
        
        ll ans = 1LL;
        
        for (auto it = cnt_freqs.rbegin(); it != cnt_freqs.rend(); ++it) {
            ll frq = it->first;
            ll occ = it->second;
            
            if (k >= occ) {
                ans = (ans * exp(frq, occ)) % MOD;
                k -= occ;
            }
            else {
                ans = (ans * C(occ, k)) % MOD;
                ans = (ans * exp(frq, k)) % MOD;
                break;
            }
        }
        
        return ans;
    }
};