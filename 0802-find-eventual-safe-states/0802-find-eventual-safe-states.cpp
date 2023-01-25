class Solution {
private:
    vector<vector<int>> graph;
    vector<int> color;
    int n;
        
public:
    bool dfs(int u) {
        if (color[u] == 2) {
            return true;
        }
        if (color[u] == 1) {
            return false;
        }
        color[u] = 1;
        for (int v : graph[u]) {
            bool check = dfs(v);
            if (!check) {
                return false;
            }
        }
        color[u] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        this->graph = graph;
        this->n = (int)graph.size();
        color.resize(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 0) {
                color[i] = 2;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                dfs(i);
            }
        }
        
        vector<int> ans;
        
        for (int i = 0; i < n; ++i) {
            if (color[i] == 2) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};