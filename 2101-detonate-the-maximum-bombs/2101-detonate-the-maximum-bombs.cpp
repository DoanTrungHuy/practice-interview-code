using ll = long long;

class Solution {
private:
    int n;
    unordered_map<int, vector<int>> adj;
    unordered_set<int> visited;

public:
    int dfs(int i) {
        visited.insert(i);
        for (int j : adj[i]) {
            if (!visited.count(j)) {
                dfs(j);
            }
        }
        return visited.size();
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        for (int i = 0; i < n; ++i) {
            ll xi = bombs[i][0];
            ll yi = bombs[i][1];
            ll ri = bombs[i][2];
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                ll xj = bombs[j][0];
                ll yj = bombs[j][1];
                ll rj = bombs[j][2];
                if (ri*ri >= (xi - xj)*(xi - xj) + (yi - yj)*(yi - yj)) {
                    adj[i].push_back(j);
                    cout << i << ' ' << j << '\n';
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            visited.clear();
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};