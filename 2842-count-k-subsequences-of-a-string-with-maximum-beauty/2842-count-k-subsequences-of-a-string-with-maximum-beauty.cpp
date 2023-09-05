using ll = long long;
const ll MOD = 1e9 + 7;
const int MN = 1e6 + 1;
ll p[MN];

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
    
    ll nCr(ll n, ll r) {
        ll res = p[n];
        res = (res * exp(p[n - r], MOD - 2)) % MOD;
        res = (res * exp(p[r], MOD - 2)) % MOD;
        return res;
    }
    
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        unordered_map<char, ll> f;
        
        for (const char c : s) {
            f[c]++;
        }
        
        if (k > (int)f.size()) {
            return 0;
        }
        
        priority_queue<int> pq;
        
        for (const auto [character, freq] : f) {
            pq.push(freq);
        }
        
        p[0] = 1;
        
        for (int i = 1; i < MN; ++i) {
            p[i] = (p[i - 1] * i) % MOD;
        }
        
        ll ans = 1LL;
        
        while (k > 0) {
            int num_way = pq.top();
            ll num_freq = 0;
            
            while (!pq.empty() and pq.top() == num_way) {
                num_freq++;
                pq.pop();
            }
            
            if (k >= num_freq) {
                ans = (ans * exp(num_way, num_freq)) % MOD;
                k -= num_freq;
            }
            else {
                ans = (((ans * nCr(num_freq, k)) % MOD) * exp(num_way, k)) % MOD;
                break;
            }
        }
        
        return ans;
    }
};