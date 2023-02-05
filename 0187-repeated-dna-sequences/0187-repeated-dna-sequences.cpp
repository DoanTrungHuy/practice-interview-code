class Solution {
public:
    using ll = long long;
    const ll base = 4;
    const ll mod = 1e9 + 7;
    const ll limit = 9;
    
    vector<string> findRepeatedDnaSequences(string s) {
        int n = (int)s.size();
        if (n < 10) {
            return {};
        }
        vector<ll> h(n + 1, 0);
        vector<ll> p(n + 1, 1);
        unordered_map<char, int> codes;
        string DNA = "ACGT";
        for (int i = 0; i < (int)DNA.size(); ++i) {
            codes[DNA[i]] = i;
        }
        for (int i = 1; i <= n; ++i) {
            h[i] = (h[i - 1]*base + codes[s[i - 1]]) % mod;
            p[i] = (p[i - 1]*base) % mod;
        }
        unordered_map<ll, int> um;
        vector<string> ans;
        for (int i = 1; i <= n - limit; ++i) {
            int l = i;
            int r = i + limit;
            if (++um[(h[r] - h[l - 1]*p[r - l + 1] + mod*mod) % mod] == 2) {
                ans.push_back(s.substr(l - 1, r - l + 1));
            }
        }
        return ans;
    }
};