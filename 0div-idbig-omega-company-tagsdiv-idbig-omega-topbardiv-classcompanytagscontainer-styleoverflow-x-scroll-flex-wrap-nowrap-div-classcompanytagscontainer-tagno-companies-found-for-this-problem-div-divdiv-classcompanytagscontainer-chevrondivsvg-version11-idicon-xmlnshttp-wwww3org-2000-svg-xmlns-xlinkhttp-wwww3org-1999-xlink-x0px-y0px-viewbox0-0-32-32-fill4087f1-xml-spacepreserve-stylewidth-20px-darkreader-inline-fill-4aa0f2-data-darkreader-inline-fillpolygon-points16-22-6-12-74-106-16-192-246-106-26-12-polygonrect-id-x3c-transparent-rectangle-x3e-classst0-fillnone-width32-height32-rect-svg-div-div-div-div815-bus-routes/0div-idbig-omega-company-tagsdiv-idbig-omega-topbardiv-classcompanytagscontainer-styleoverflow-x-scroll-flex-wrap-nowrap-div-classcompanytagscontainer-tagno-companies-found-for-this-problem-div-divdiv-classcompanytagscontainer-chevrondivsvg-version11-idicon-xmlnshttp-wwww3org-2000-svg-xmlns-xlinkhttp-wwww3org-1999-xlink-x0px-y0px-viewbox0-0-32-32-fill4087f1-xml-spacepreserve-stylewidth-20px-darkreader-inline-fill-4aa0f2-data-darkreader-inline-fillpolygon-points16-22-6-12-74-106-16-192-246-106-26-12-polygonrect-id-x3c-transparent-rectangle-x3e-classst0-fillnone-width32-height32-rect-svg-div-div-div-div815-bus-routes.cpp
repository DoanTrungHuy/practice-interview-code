class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        const int n = routes.size();
        unordered_map<int, vector<int>> adj;
        
        if (n == 0 or source == target) {
            return 0;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int val : routes[i]) {
                adj[val].push_back(i);
            }
        }
        
        int step = 0;
        unordered_set<int> us;
        queue<int> mq;
        us.insert(source);
        mq.push(source);
        
        while (!mq.empty()) {
            int m = mq.size();
            while (m--) {
                int u = mq.front();
                mq.pop();
                
                if (u == target) {
                    return step;
                }

                for (int i : adj[u]) {
                    for (int val : routes[i]) {
                        if (us.find(val) == us.end()) {
                            mq.push(val);
                            us.insert(val);
                        }
                    }
                    routes[i].clear();
                }
            }
            
            step++;
        }
        
        return -1;
    }
};