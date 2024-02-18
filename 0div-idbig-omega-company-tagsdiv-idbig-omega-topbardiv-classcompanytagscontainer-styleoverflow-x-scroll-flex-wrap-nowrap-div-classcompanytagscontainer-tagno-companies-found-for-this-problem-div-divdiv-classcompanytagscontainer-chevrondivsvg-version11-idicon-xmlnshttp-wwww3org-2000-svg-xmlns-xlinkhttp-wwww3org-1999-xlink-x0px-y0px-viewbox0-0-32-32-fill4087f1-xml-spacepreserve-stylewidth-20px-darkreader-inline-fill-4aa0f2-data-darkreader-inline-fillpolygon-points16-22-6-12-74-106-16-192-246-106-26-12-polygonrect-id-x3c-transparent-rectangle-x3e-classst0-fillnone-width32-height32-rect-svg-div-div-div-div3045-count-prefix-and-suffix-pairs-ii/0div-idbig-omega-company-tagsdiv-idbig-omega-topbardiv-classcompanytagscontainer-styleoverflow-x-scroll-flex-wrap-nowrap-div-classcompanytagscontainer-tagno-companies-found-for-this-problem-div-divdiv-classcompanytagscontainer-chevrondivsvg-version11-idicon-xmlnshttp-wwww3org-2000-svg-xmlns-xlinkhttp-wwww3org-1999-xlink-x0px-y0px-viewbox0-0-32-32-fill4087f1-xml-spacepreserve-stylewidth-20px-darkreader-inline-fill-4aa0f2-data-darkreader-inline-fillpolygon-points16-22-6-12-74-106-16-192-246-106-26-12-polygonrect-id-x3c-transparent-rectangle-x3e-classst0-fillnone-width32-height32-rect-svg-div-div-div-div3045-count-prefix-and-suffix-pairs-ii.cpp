class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        unordered_map<long long, long long> um;
        long long ans = 0;
        const long long BASE = 131, MOD = 1e9 + 131313;
        
        for (string w : words) {
            long long pref = 0;
            long long suff = 0;
            const int m = w.size();
            long long power = 1;
            
            for (int i = 0; i < m; ++i) {
                pref = (pref*BASE + (w[i] - 'a' + 1)) % MOD;
                suff = (power*(w[m - i - 1] - 'a' + 1) + suff) % MOD;
                power = (power*BASE) % MOD;
                if (pref == suff) {
                    ans += um[pref];
                }
            }
            
            um[pref]++;
        }
        
        return ans;
    }
};