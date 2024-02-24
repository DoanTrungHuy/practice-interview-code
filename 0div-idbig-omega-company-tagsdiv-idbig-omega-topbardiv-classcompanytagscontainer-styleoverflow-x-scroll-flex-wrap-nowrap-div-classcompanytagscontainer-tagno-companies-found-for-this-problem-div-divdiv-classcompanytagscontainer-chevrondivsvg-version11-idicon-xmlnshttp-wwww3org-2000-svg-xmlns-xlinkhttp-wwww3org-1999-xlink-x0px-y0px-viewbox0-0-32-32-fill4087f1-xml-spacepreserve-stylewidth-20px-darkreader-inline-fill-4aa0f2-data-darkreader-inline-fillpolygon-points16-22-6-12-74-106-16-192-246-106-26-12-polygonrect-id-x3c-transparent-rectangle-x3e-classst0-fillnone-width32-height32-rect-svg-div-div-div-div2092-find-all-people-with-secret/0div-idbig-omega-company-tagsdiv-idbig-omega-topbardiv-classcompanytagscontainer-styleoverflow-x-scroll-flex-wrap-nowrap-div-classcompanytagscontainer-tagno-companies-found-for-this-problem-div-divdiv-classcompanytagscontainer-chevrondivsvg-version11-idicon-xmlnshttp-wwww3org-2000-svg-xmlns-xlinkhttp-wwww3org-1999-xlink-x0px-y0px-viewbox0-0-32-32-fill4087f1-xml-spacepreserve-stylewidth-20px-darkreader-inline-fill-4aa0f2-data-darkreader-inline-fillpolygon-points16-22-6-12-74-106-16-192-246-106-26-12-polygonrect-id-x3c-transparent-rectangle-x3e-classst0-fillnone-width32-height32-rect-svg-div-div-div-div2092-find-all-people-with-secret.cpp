class Solution {
private:
    vector<int> parent;
    
public:
    int find(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    
    bool _union(int u, int v) {
        u = find(u);
        v = find(v);
        
        if (u == v) {
            return true;
        }
        
        parent[u] = v;
        
        return false;
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        sort(meetings.begin(), meetings.end(), [](vector<int> a, vector<int> b) {
           return a[2] < b[2]; 
        });
        _union(0, firstPerson);
        const int m = meetings.size();
        map<int, vector<pair<int, int>>> um;
        for (int i = 0; i < m; ++i) {
            int u = meetings[i][0];
            int v = meetings[i][1];
            int t = meetings[i][2];
            um[t].push_back({u, v});
        }
        for (auto [t, sav] : um) {
            for (auto [u, v] : sav) {
                _union(u, v);
            }
            for (auto [u, v] : sav) {
                if (find(u) != find(0) or find(v) != find(0)) {
                    parent[u] = u;
                    parent[v] = v;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (find(i) == find(0)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};