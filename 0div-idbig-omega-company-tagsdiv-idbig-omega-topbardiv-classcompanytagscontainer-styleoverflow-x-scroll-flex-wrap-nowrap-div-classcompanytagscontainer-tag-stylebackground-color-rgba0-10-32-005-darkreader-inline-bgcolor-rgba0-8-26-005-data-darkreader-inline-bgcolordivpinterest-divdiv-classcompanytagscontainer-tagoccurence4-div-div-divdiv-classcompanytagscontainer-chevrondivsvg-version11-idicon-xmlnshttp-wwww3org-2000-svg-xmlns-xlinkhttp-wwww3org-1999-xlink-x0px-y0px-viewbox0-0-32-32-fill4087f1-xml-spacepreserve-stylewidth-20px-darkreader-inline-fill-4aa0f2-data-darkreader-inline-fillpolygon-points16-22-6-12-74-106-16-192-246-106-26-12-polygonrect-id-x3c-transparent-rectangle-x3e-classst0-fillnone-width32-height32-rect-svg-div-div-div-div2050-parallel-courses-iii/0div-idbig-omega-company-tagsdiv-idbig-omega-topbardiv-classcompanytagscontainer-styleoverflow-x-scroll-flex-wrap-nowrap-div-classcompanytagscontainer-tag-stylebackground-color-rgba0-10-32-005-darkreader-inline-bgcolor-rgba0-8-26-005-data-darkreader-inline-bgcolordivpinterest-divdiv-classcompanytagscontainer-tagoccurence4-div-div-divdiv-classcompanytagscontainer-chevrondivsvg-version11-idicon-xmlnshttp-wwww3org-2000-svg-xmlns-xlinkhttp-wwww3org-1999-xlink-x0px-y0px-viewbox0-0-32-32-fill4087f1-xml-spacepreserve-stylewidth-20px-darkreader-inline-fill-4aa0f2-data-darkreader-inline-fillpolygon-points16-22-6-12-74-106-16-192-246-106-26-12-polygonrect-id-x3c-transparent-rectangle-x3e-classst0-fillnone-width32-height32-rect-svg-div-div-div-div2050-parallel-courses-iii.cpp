const int MN = 5e4 + 1;
int memo[MN];

class Solution {
private:
    vector<int> max_prev, time;
    vector<vector<int>> adj;

public:
    int dfs(int u) {
        if (memo[u] != -1) {
            return memo[u];
        }
        for (int v : adj[u]) {
            max_prev[u] = max(max_prev[u], dfs(v));
        }
        max_prev[u] = memo[u] = max_prev[u] + time[u];
        return memo[u];
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        this->time = time;
        int indegree[n];
        memset(indegree, 0, sizeof(indegree));
        adj.resize(n);
        for (vector<int> r : relations) {
            int u = r[0] - 1;
            int v = r[1] - 1;
            indegree[u]++;
            adj[v].push_back(u);
        }
        memset(memo, -1, sizeof(memo));
        max_prev.resize(n);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                dfs(i);
                res = max(res, max_prev[i]);
            }
        }
        return res;
    }
};