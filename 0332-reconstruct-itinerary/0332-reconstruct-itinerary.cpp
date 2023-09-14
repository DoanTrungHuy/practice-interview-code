class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> ans;
    
public:
    void dfs(string u) {
        while (adj[u].size()) {
            string v = adj[u].top();
            adj[u].pop();
            dfs(v);
        }
        ans.push_back(u);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (vector<string> ticket : tickets) {
            string u = ticket[0];
            string v = ticket[1];
            adj[u].push(v);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};