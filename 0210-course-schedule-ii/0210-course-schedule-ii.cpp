class Solution {
    map<int, vector<int>> adj;
    vector<int> color;
    vector<int> ans;

public:
    bool dfs(int u) {
        color[u] = 1;

        for (int v : adj[u]) {
            if (color[v] == 0 && !dfs(v)) {
                return false;
            }
            else if (color[v] == 1) {
                return false;
            }
        }

        ans.push_back(u);
        color[u] = 2;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        color.resize(numCourses);
        const int n = numCourses;

        for (vector<int> p : prerequisites) {
            int u = p[0], v = p[1];
            adj[u].push_back(v);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (color[i] == 0 && !dfs(i)) {
                return {};
            }
        }

        return ans;
    }
};