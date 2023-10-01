class Solution {
private:
    vector<vector<int>> adj;
    int time = 0, idSCC = 0;
    vector<int> color, low, del;
    stack<int> st;
    unordered_map<int, int> group;
    vector<int> num_scc;
    
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
        
        const int LOG = 1 + log2(n);
        vector<vector<pair<int, int>>> parent(idSCC + 1, vector<pair<int, int>>(LOG + 1, {-1, 0}));
        
        for (int i = 0; i < n; ++i) {
            if (num_scc[i] != num_scc[edges[i]]) {
                parent[num_scc[i]][0].first = num_scc[edges[i]];
                parent[num_scc[i]][0].second = group[num_scc[edges[i]]];
            }
        }
        
        for (int j = 1; j <= LOG; ++j) {
            for (int i = 1; i <= idSCC; ++i) {
                if (parent[i][j - 1].first != -1) {
                    parent[i][j].first = parent[parent[i][j - 1].first][j - 1].first;
                    parent[i][j].second = parent[i][j - 1].second + parent[parent[i][j - 1].first][j - 1].second; 
                }
            }
        }
        
        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i) {
            int step = group[num_scc[i]];
            int node = num_scc[i];
            for (int j = LOG; j >= 0; --j) {
                if (parent[node][j].first != -1) {
                    step += parent[node][j].second;
                    node = parent[node][j].first;
                }
            }
            ans[i] = step;
        }
        
        return ans;
    }
};