class Solution {
private:
    int n;
    vector<vector<int>> ans, adj;
    vector<int> tmp;
    
public:
    void backTracking(vector<vector<int>>& graph, int u) {
        if (u == n - 1) {
            ans.push_back(tmp);
            return;
        }
        for (int v : graph[u]) {
            tmp.push_back(v);
            backTracking(graph, v);
            tmp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->n = graph.size();
        adj.resize(n);
        tmp.push_back(0);
        backTracking(graph, 0);
        return ans;
    }
};