#define WHITE 0
#define GRAY 1
#define BLACK 2

class Solution {
private:
    vector<vector<int>> graph;
    vector<int> color;
    int n;
        
public:
    bool dfs(int u) {
        if (color[u] == BLACK) {
            return true;
        }
        if (color[u] == GRAY) {
            return false;
        }
        color[u] = GRAY;
        for (int v : graph[u]) {
            bool check = dfs(v);
            if (!check) {
                return false;
            }
        }
        color[u] = BLACK;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        this->graph = graph;
        this->n = (int)graph.size();
        color.resize(n, WHITE);
        
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 0) {
                color[i] = BLACK;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (color[i] == WHITE) {
                dfs(i);
            }
        }
        
        vector<int> ans;
        
        for (int i = 0; i < n; ++i) {
            if (color[i] == BLACK) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};