class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n), revAdj(n);
        
        for (vector<int> connection : connections) {
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back(v), revAdj[v].push_back(u);
        }
        
        queue<int> mq;
        vector<bool> visited(n);
        mq.push(0);
        int ans = 0;
        
        while (!mq.empty()) {
            int u = mq.front();
            mq.pop();
            visited[u] = true;
            
            for (int v : adj[u]) {
                if (!visited[v]) {
                    ans++;
                    mq.push(v);
                }
            }
            
            for (int v : revAdj[u]) {
                if (!visited[v]) {
                    mq.push(v);
                }
            }
        }
        
        return ans;
    }
};