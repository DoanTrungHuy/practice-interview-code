using ll = long long;
const int MN = 1e5 + 1, MOD = 1e9 + 7;
ll fact[MN];

class Solution {
private:
    int n;
    vector<vector<int>> adj;
    vector<int> dp, sz;
    
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
    
    int dfs(int node) {
        if (adj[node].size() == 0) {
            return 1;
        }
        for (int child : adj[node]) {
            dfs(child);
            sz[node] += sz[child];
            dp[node] = (1LL*dp[node]*exp(fact[sz[child]], MOD - 2)) % MOD;
        }
        dp[node] = (1LL*dp[node]*fact[sz[node] - 1]) % MOD;
        return dp[node];
    }
    
    int waysToBuildRooms(vector<int>& prevRoom) {
        this->n = prevRoom.size();
        adj.resize(n);
        for (int i = 0; i < n; ++i) {
            if (prevRoom[i] != -1) {
                adj[prevRoom[i]].push_back(i);
            }
        }
        fact[0] = 1LL;
        for (int i = 1; i <= n; ++i) {
            fact[i] = (fact[i - 1]*i) % MOD;
        }
        dp.resize(n, 1), sz.resize(n, 1);
        dfs(0);
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            ans = (1LL*ans*dp[i]) % MOD;
        }
        return ans;
    }
};