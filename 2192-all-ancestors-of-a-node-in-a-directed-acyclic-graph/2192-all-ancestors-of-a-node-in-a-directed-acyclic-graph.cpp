class Solution
{
private:
    vector<vector<int>> adj, ans;
    vector<int> dist, tmp;

public:
    void dfs(int u, int n)
    {
        dist[u] = 1;
        for (int v : adj[u])
        {
            if (!dist[v])
            {
                tmp.push_back(v);
                dfs(v, n);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        adj.resize(n);
        for (vector<int> d : edges)
        {
            adj[d[1]].push_back(d[0]);
        }
        for (int i = 0; i < n; ++i)
        {
            dist = vector<int>(n, 0);
            dfs(i, n);
            sort(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};