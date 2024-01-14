using ll = long long;

class Solution {
public:
    vector<int> get_idx(string &s, string &a) {
        const ll BASE = 71;
        const ll MOD = 1e9 + 7;
        vector<ll> h, p;
        const int n = s.size();
        const int m = a.size();
        
        h.resize(n + 1, 0);
        p.resize(n + 1, 0);
        p[0] = 1;
        
        ll hash_a = 0;
        
        for (int i = 1; i <= n; ++i) {
            h[i] = (h[i - 1]*BASE + s[i - 1]) % MOD;
            p[i] = (p[i - 1]*BASE) % MOD;
        }
        
        for (int i = 1; i <= m; ++i) {
            hash_a = (hash_a*BASE + a[i - 1]) % MOD;
        }
        
        auto get_hash = [&](int i, int j) {
            return (h[j] - (h[i - 1]*p[j - i + 1]) % MOD + MOD*MOD) % MOD;
        };
        
        vector<int> ans;
        
        for (int i = 1; i <= n - m + 1; ++i) {
            if (get_hash(i, i + m - 1) == hash_a) {
                ans.push_back(i - 1);
            }
        }
        
        return ans;
    }
    
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> idx_a = get_idx(s, a);
        vector<int> idx_b = get_idx(s, b);
        
        vector<int> ans;
        
        for (int i : idx_a) {
            auto lb = lower_bound(idx_b.begin(), idx_b.end(), i - k);
            auto rb = upper_bound(idx_b.begin(), idx_b.end(), i + k);
            
            if (rb - lb) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};