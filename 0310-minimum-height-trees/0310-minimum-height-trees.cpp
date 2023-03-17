class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        
        vector<vector<int>> adj(n);
        vector<int> degrees(n);
        
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degrees[u]++;
            degrees[v]++;
        }
        
        queue<int> mq;
        
        for (int u = 0; u < n; ++u) {
            if (adj[u].size() == 1) {
                mq.push(u);
                degrees[u]--;
            }
        }
        
        vector<int> ans;
        
        while (!mq.empty()) {
            int m = mq.size();
            ans.clear();
            while (m--) {
                int u = mq.front();
                mq.pop();
                ans.push_back(u);
                for (int v : adj[u]) {
                    degrees[v]--;
                    if (degrees[v] == 1) {
                        mq.push(v);
                    }
                }
            }
        }
        
        return ans;
    }
};