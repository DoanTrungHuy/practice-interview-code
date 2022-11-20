class Solution {
public:
    int seat;
    long long ans = 0;
    vector<vector<int>> adj;
    vector<int> tree;
    void dfs(int root, int prev)
    {
        tree[root] = 1;
        for(auto x : adj[root])
        {
            if(x != prev)
             {
                 dfs(x, root);
                 ans += (tree[x] + seat - 1) / seat;
                 tree[root] += tree[x];
             }
        }
    }
    long long minimumFuelCost(vector<vector<int>>& e, int seat) {
        int n = e.size() + 1;
        this->seat = seat;
        adj.resize(n + 1), tree.resize(n + 1);
        for(auto x : e) 
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0, -1);
        return ans;
    }
};