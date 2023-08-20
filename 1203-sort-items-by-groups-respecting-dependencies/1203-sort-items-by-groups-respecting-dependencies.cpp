class Solution {
private:
    int n, m;
    
public:
    vector<int> topo(vector<vector<int>> &adj, vector<int> &indegree) {
        queue<int> mq;
        for (int u = 0; u < max(n, m); ++u) {
            if (indegree[u] == 0) {
                mq.push(u);
            }
        }
        vector<int> ans;
        while (!mq.empty()) {
            int u = mq.front();
            mq.pop();
            ans.push_back(u);
            for (int v : adj[u]) {
                if (--indegree[v] == 0) {
                    mq.push(v);
                }
            }
        }
        return ans;
    }
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        this->n = n;
        
        for (int u = 0; u < n; ++u) {
            if (group[u] == -1) {
                group[u] = m++;
            }
        }
        
        this->m = m;
        
        vector<vector<int>> adj[2];
        vector<int> indegree[2];
        
        for (int i = 0; i < 2; ++i) {
            adj[i].resize(max(n, m));
            indegree[i].resize(max(n, m));
        }
        
        for (int v = 0; v < n; ++v) {
            for (int u : beforeItems[v]) {
                adj[0][u].push_back(v);
                indegree[0][v]++;
                
                if (group[u] != group[v]) {
                    adj[1][group[u]].push_back(group[v]);
                    indegree[1][group[v]]++;
                }
            }
        }
        
        vector<int> items = topo(adj[0], indegree[0]);
        vector<int> gs = topo(adj[1], indegree[1]);
        
        unordered_map<int, vector<int>> um;
        
        for (int u : items) {
            um[group[u]].push_back(u);
        }
        
        vector<int> ans;
        
        for (int u : gs) {
            for (int v : um[u]) {
                ans.push_back(v);
            }
        }
        
        if (ans.size() != n) {
            return {};
        }
        
        return ans;
    }
};