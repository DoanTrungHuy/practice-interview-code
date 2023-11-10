class Solution {
private:
    unordered_map<int, vector<int>> adj;
    
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        const int n = adjacentPairs.size();
        
        for (const vector<int> edge : adjacentPairs) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> mq;
        
        for (const auto [u, a] : adj) {
            if (a.size() == 1) {
                mq.push(u);
                break;
            }
        }
        
        vector<int> ans;
        unordered_set<int> us;
        
        while (!mq.empty()) {
            int u = mq.front();
            mq.pop();
            
            ans.push_back(u);
            us.insert(u);
            
            for (int v : adj[u]) {
                if (!us.count(v)) {
                    mq.push(v);
                }
            }
        }
        
        return ans;
    }
};