class Solution {
private:
    vector<vector<int>> adj;
    int time = 0, idSCC = 0;
    vector<int> color, low, del;
    stack<int> st;
    unordered_map<int, int> group;
    vector<int> num_scc;
    vector<vector<int>> adj_dag;
    vector<bool> visited;
    vector<int> dp;
    
public:
    void dfs(int u) {
        color[u] = low[u] = ++time;
        st.push(u);
        for (int v : adj[u]) {
            if (del[v]) {
                continue;
            }
            if (color[v]) {
                low[u] = min(low[u], color[v]);
            }
            else {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
        if (color[u] == low[u]) {
            int len = st.size();
            int t;
            ++idSCC;
            do {
                t = st.top();
                st.pop();
                num_scc[t] = idSCC;
                del[t] = 1;
            } while (u != t);
        }
    }
    
    void dfs_dag(int u) {
        visited[u] = true;
        dp[u] = group[u];
        for (int v : adj_dag[u]) {
            if (!visited[v]) {
                dfs_dag(v);
            }
            dp[u] += dp[v];
        }
    };
    
    vector<int> countVisitedNodes(vector<int>& edges) {
        const int n = edges.size();
        adj.resize(n);
        color.resize(n), low.resize(n), del.resize(n);
        
        for (int i = 0; i < n; ++i) {
            adj[i].push_back(edges[i]);
        }
        
        num_scc.resize(n);
        
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                dfs(i);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            group[num_scc[i]]++;
        }
        
        adj_dag.resize(n + 1);
        
        int indegree[n + 1];
        memset(indegree, 0, sizeof(indegree));
        
        for (int i = 0; i < n; ++i) {
            if (num_scc[i] != num_scc[edges[i]]) {
                adj_dag[num_scc[i]].push_back(num_scc[edges[i]]);
                indegree[num_scc[edges[i]]]++;
            }
        }
        
        visited.resize(n, false);
        
        dp.resize(n + 1);
        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i) {
            if (indegree[num_scc[i]] == 0) {
                dfs_dag(num_scc[i]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            ans[i] = dp[num_scc[i]];
        }
        
        return ans;
    }
};