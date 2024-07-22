class Solution {
private:
    vector<int> degree, visited;
    
public:
    int longestCycle(vector<int>& edges) {
        const int n = edges.size();
        
        degree.resize(n);
        visited.resize(n);
        
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) {
                degree[edges[i]]++;
            }
        }
        
        queue<int> mq;
        
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 0) {
                mq.push(i);
            }
        }
        
        while (!mq.empty()) {
            int u = mq.front();
            mq.pop();
            visited[u] = true;
            
            int v = edges[u];
            
            if (v == -1) {
                continue;
            }
            
            degree[v]--;
            if (degree[v] == 0) {
                mq.push(v);
            }
        }
        
        int ans = -1;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int u = i;
                int cnt = 0;
                
                while (!visited[u]) {
                    cnt++;
                    visited[u] = true;
                    u = edges[u];
                }
                
                ans = max(ans, cnt);
            }
        }
        
        return ans;
    }
};