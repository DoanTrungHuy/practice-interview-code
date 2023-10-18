const int MN = 5e4 + 1;
int memo[MN];

class Solution {
private:
    vector<int> time;
    vector<vector<int>> adj;

public:
    int dfs(int u) {
        if (memo[u] != -1) {
            return memo[u];
        }
        int ans = 0;
        for (int v : adj[u]) {
            ans = max(ans, dfs(v));
        }
        memo[u] = ans + time[u];
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
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                res = max(res, dfs(i));
            }
        }
        return res;
    }
};