class Solution {
private:
    vector<vector<int>> ans;
    map<int, vector<int>> adj;

public:
    void dfs(int u) {
        while (adj[u].size()) {
            int v = adj[u].back();
            adj[u].pop_back();
            dfs(v);
            ans.push_back({u, v});
        }        
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int, int> indegree;
        
        for (vector<int> p : pairs) {
            int u = p[0];
            int v = p[1];
            adj[u].push_back(v);
            indegree[u]++;
            indegree[v]--;
        }
        
        int start = -1;
        
        for (auto [v, cnt] : indegree) {
            if (cnt > 0) {
                start = v;
                break;
            }
        }
        
        if (start == -1) {
            start = pairs[0][0];
        }
        
        dfs(start);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};