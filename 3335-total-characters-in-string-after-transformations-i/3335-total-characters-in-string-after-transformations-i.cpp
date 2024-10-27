int memo[26][100005];
const int MOD = 1e9 + 7;

class Solution {
private:
    vector<vector<int>> adj;
    
public:
    int dp(int c, int times) {
        if (times == 0) {
            return 1;
        }
        if (memo[c][times] != -1) {
            return memo[c][times];
        }
        int ans = 0;
        for (int next_c : adj[c]) {
            ans = (ans + dp(next_c, times - 1)) % MOD;
        }
        return memo[c][times] = ans;
    };
    
    int lengthAfterTransformations(string s, int t) {
        adj.resize(26);
        
        for (int i = 0; i < 26; ++i) {
            if (i == 25) {
                adj[i].push_back(0);
                adj[i].push_back(1);
            } 
            else {
                adj[i].push_back(i + 1);
            }
        }
        
        memset(memo, -1, sizeof memo);
        map<int, int> mm;
        long long ans = 0;
        
        for (char c : s) {
            mm[c - 'a']++;
        }
        
        for (auto [k, v] : mm) {
            ans = (ans + 1LL*v*dp(k, t)) % MOD;
        }
        
        return ans;
    }
};