class Solution {
private:
    vector<vector<int>> adj;
    unordered_map<int, int> cnt;
    string s;
    
public:
    long long dfs(int u, int mask) {
        long long ans = cnt[mask];
        
        for (int i = 0; i < 26; ++i) {
            ans += cnt[mask ^ (1 << i)];
        }
        
        cnt[mask]++;
        
        for (int v : adj[u]) {
            ans += dfs(v, mask ^ (1 << (s[v] - 'a')));
        }
        
        return ans;
    }
    
    long long countPalindromePaths(vector<int>& parent, string s) {
        this->s = s;
        int n = parent.size();
        adj.resize(n + 1);
        
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                continue;
            }
            adj[parent[i]].push_back(i);
        }
        
        return dfs(0, 0);
    }
};